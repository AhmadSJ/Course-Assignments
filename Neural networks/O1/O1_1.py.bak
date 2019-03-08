import numpy as np
import matplotlib.pyplot as plt

train_in=np.genfromtxt("train_in.csv", delimiter=',');
train_out=np.genfromtxt("train_out.csv", delimiter=',');
test_in=np.genfromtxt("test_in.csv", delimiter=',');
test_out=np.genfromtxt("test_out.csv", delimiter=',');

NUM_TRAIN=len(train_out);
NUM_TEST=len(test_out);

def get_clouds(data_in, data_out):
	clouds=[[]]*10;
	for i in range(0, NUM_TRAIN):
		digit=data_out[i];
		digit_index=np.int(digit);
		if clouds[digit_index]==[]:
			clouds[digit_index]=data_in[i];
		else:
			clouds[digit_index]=np.vstack([clouds[digit_index], data_in[i]]);
	return clouds;
	
def get_centres(clouds):
	centres=np.empty([10, 256]);	
	for i in range(0, 10):
		centres[i]=np.mean(clouds[i], axis=0);	
	return centres;

def get_npoints(clouds):
	npoints=np.empty(10);
	for i in range(0, 10):
		npoints[i]=clouds[i].shape[0];
	return npoints;

def get_radii(clouds, centres):
	radii=np.empty(10);	
	for i in range(0, 10):
		radii[i]=np.sqrt(max(np.sum((clouds[i]-centres[i])**2, axis=1)));	
	return radii;

def get_centre_distances(centres):
	dist=np.zeros([10, 10]);
	for i in range(0, 10):
		for j in range(0, i):
			dist[i, j]=np.sqrt(sum((centres[i]-centres[j])**2));
	dist=dist+np.transpose(dist);
	return dist;

train_clouds=get_clouds(train_in, train_out);
train_centres=get_centres(train_clouds);
train_npoints=get_npoints(train_clouds);
train_radii=get_radii(train_clouds, train_centres);
train_centre_distances=get_centre_distances(train_centres);