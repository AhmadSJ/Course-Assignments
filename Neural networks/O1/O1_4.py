import numpy as np;
import matplotlib.pyplot as plt;

rand=np.random.rand;

test_in=np.genfromtxt("test_in.csv", delimiter=',');
test_out=np.genfromtxt("test_out.csv", delimiter=',');
train_in=np.genfromtxt("train_in.csv", delimiter=',');
train_out=np.genfromtxt("train_out.csv", delimiter=',');

NUM_TRAIN=len(train_out);
NUM_TEST=len(test_out);

c_train=np.zeros(50);
c_test=np.zeros(50);

rate=5;
for epochs in range(1, 51):
	print(epochs);
	w=rand(10, 256);
	w_b=rand(10);

	y=np.zeros(10);

	#epochs=100;
	for i in range(0, epochs):
		for j in range(0, NUM_TRAIN):
			x=train_in[j];
			c=np.int(train_out[j]);
			
			a=w_b+np.sum(w*x, axis=1);
			y=2*(a>=0)-1;
			
			for k in range(0, 10):
				delta=2*(k==c)-1-y[k];
				if delta!=0:
					w[k]=w[k]+rate*delta*x;
					w_b[k]=w_b[k]+rate*delta;

	correct_train=0;
	for i in range(0, NUM_TRAIN):
		x=train_in[i];
		c=np.int(train_out[i]);
		a=w_b+np.sum(w*x, axis=1);
		#y=2*(a>=0)-1;
		if(np.argmax(a)==c):
			correct_train=correct_train+1;
	c_train[epochs-1]=correct_train;

	correct_test=0;
	for i in range(0, NUM_TEST):
		x=test_in[i];
		c=np.int(test_out[i]);
		a=w_b+np.sum(w*x, axis=1);
		#y=2*(a>=0)-1;
		if(np.argmax(a)==c):
			correct_test=correct_test+1;
	c_test[epochs-1]=correct_test;

np.savetxt("c_train.txt", c_train, delimiter='\n', newline='\n', fmt='%d');
np.savetxt("c_test.txt", c_test, delimiter='\n', newline='\n', fmt='%d');