import numpy as np;
import codecs as co;
np.set_printoptions(threshold=np.nan);

chars_right=8;
seq_length=16;

def read_in(filename, destination):
	chars=[32]*seq_length;
	din=[];
	f=open(filename, "r");
	i=0;
	
	while True:
		C=f.read(1);
		if not C:
			break;
		c = ord(C.upper());
		chars=chars[1:seq_length];
		chars.append(c);
		#print(chars);
		m=chars[seq_length-1-chars_right];
		if m==65 or m==69 or m==73 or m==79 or m==85:
			i=i+1;
			if i%5000==0:
				print(i);
			if din==[]:
				din=chars;
			else:
				din=np.vstack([din, chars]);
	
	for i in range(chars_right):
		chars=chars[1:seq_length];
		chars.append(32);
		m=chars[seq_length-1-chars_right];
		if m==65 or m==69 or m==73 or m==79 or m==85:
			i=i+1;
			din=np.vstack([din, chars]);
	
	np.savetxt(destination, din, fmt='%d');

def read_out(filename, destination):
	dout=[];
	f=co.open(filename, "r", encoding='utf-8');
	i=0;
	
	while True:
		C=f.read(1);
		if not C:
			break;
		c=ord(C.upper());
		if c==65 or c==69 or c==73 or c==79 or c==85:
			dout.append([1, 0, 0, 0]);
		elif c==193 or c==201 or c==205 or c==211 or c==218:
			dout.append([0, 1, 0, 0]);
		elif c==214 or c==220:
			dout.append([0, 0, 1, 0]);
		elif c==336 or c==368:
			dout.append([0, 0, 0, 1]);
	
	np.savetxt(destination, dout, fmt='%d');

#read_in("data/text/text_in_num.txt", "data/train_num.txt");
#read_out("data/text/text_in_lab.txt", "data/train_lab.txt");
read_in("data/text/_Legy jo mindhalalaig.txt", "data/test_num.txt");
read_out("data/text/Legy jo mindhalalaig.txt", "data/test_lab.txt");