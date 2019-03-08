import tensorflow as tf;
import numpy as np;
import codecs as co;

chars_right=8;
seq_length=16;

feature_size=seq_length/2;
features=64;
fullnodes=256;
#epochs=2500;
batch_size=100;

sess=tf.InteractiveSession();

x=tf.placeholder(tf.float32, [None, seq_length]);
y_=tf.placeholder(tf.float32, [None, 4]);

def weight_variable(shape):
	initial=tf.truncated_normal(shape, stddev=0.1);
	return tf.Variable(initial);

def bias_variable(shape):
	initial=tf.constant(0.1, shape=shape);
	return tf.Variable(initial);

def conv2d(x, W):
	return tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='SAME');

def max_pool_2x2(x):
	return tf.nn.max_pool(x, ksize=[1, 2, 1, 1], strides=[1, 2, 1, 1], padding='SAME');

x_im=tf.reshape(x, [-1, seq_length, 1, 1]);	

W_conv1=weight_variable([feature_size, 1, 1, features/2]);
b_conv1=bias_variable([features/2]);

h_conv1=tf.nn.relu(conv2d(x_im, W_conv1)+b_conv1);
h_pool1=max_pool_2x2(h_conv1);

W_conv2=weight_variable([feature_size, 1, features/2, features]);
b_conv2=bias_variable([features]);

h_conv2=tf.nn.relu(conv2d(h_pool1, W_conv2)+b_conv2);
h_pool2=max_pool_2x2(h_conv2);

W_fc1=weight_variable([features*seq_length/4, fullnodes]);
b_fc1=bias_variable([fullnodes]);

h_pool2_f=tf.reshape(h_pool2, [-1, features*seq_length/4]);
h_fc1=tf.nn.relu(tf.matmul(h_pool2_f, W_fc1)+b_fc1);

keep_prob=tf.placeholder(tf.float32);
h_fc1_drop=tf.nn.dropout(h_fc1, keep_prob);

W_fc2=weight_variable([fullnodes, 4]);
b_fc2=bias_variable([4]);

y=tf.nn.relu(tf.matmul(h_fc1_drop, W_fc2)+b_fc2);

cross_entropy=tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=y_, logits=y));
train_step=tf.train.AdamOptimizer(1e-4).minimize(cross_entropy);
correct_prediction=tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1));
accuracy=tf.reduce_mean(tf.cast(correct_prediction, tf.float32));
sess.run(tf.global_variables_initializer());

def reset():
	sess.run(tf.global_variables_initializer());

def train(epochs):
	train_in=np.loadtxt("data/train_num.txt", dtype='int');
	print("read training input data");
	train_out=np.loadtxt("data/train_lab.txt", dtype='int');
	print("read training output data");
	for i in range(epochs):
		random_batch_indices=np.random.randint(train_in.shape[0], size=batch_size);
		batch_x=train_in[random_batch_indices, :];
		batch_y=train_out[random_batch_indices, :];
		if i%100 == 0:
			train_accuracy = accuracy.eval(feed_dict={x: batch_x, y_: batch_y, keep_prob: 1.0});
			print("step %d, training accuracy %g"%(i, train_accuracy));
		sess.run(train_step, feed_dict={x: batch_x, y_: batch_y, keep_prob: 0.5});

def test():
	test_in=np.loadtxt("data/test_num.txt", dtype='int');
	print("read testing input data");
	test_out=np.loadtxt("data/test_lab.txt", dtype='int');
	print("read testing output data");
	print("test accuracy %g"%accuracy.eval(feed_dict={x: test_in, y_: test_out, keep_prob: 1.0}));
	
def apply(source, destination):
	r=open(source, "r");
	w=open(destination, "w");
	chars=[32]*seq_length;
	upper=[True]*seq_length;
	out="";
	cout="";
	i=0;
		
	def clower(char):
		o=ord(char);
		if o>=44 or (o>=32 and o<=34):
			return char.lower();
		elif o>=20 and o<=31:
			return chr(o+15);
		else:
			return char;
	
	for i in range(chars_right):
		C=r.read(1);
		if not C:
			break;
		c=ord(C.upper());
		u=C.isupper();
		chars=chars[1:seq_length];
		chars.append(c);
		upper=upper[1:seq_length];
		upper.append(u);
	
	while True:
		i=i+1;
		if i%50==0: print(i);
		C=r.read(1);
		if not C:
			break;
		c=ord(C.upper());
		u=C.isupper();
		chars=chars[1:seq_length];
		chars.append(c);
		upper=upper[1:seq_length];
		upper.append(u);
		
		m=chars[seq_length-1-chars_right];
		if m==65 or m==69 or m==73 or m==79 or m==85:
			out_type=tf.argmax(y, 1).eval(feed_dict=
				{
					x: np.reshape(chars, [1, seq_length]),
					y_: np.reshape([0, 0, 0, 0], [1, 4]),
					keep_prob: 1.0
				}
			);
			if m==65:
				if out_type==0:
					cout="A";
				elif out_type==1:
					cout=chr(20); #A'
				elif out_type==2:
					cout="A";
				elif out_type==3:
					cout=chr(20); #A'
			elif m==69:
				if out_type==0:
					cout="E";
				elif out_type==1:
					cout=chr(21); #E'
				elif out_type==2:
					cout="E";
				elif out_type==3:
					cout=chr(21); #E'
			elif m==73:
				if out_type==0:
					cout="I";
				elif out_type==1:
					cout=chr(22); #I'
				elif out_type==2:
					cout="I";
				elif out_type==3:
					cout=chr(22); #I'
			elif m==79:
				if out_type==0:
					cout="O";
				elif out_type==1:
					cout=chr(23); #O'
				elif out_type==2:
					cout=chr(24); #O:
				elif out_type==3:
					cout=chr(25); #O"
			elif m==85:
				if out_type==0:
					cout="U";
				elif out_type==1:
					cout=chr(26); #U'
				elif out_type==2:
					cout=chr(27); #U:
				elif out_type==3:
					cout=chr(28); #U"
		else: cout=chr(m);
		out=out+(cout if upper[seq_length-1-chars_right] else clower(cout));	
	
	w.write(out);
	r.close();
	w.close();