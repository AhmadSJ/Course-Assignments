import numpy as np;
import matplotlib.pyplot as plt;
import sklearn.metrics as skm;

NUM_TEST=1000;
NUM_TRAIN=1707;

test_in=np.genfromtxt("test_in.csv", delimiter=',');
test_out=np.genfromtxt("test_out.csv", delimiter=',');
train_in=np.genfromtxt("train_in.csv", delimiter=',');
train_out=np.genfromtxt("train_out.csv", delimiter=',');

def euclidian_dist(x, y):
	return np.sqrt(sum((x-y)**2));

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

def classify(data_in, centres, metr):
	distances = skm.pairwise.pairwise_distances(data_in, centres, metric = metr);
	classes = distances.argmin(axis = 1);
	return classes;


train_clouds=get_clouds(train_in, train_out); 
train_centres=get_centres(train_clouds);

np.set_printoptions(precision=3);

metrics=['euclidean', 'cityblock', 'cosine', 'braycurtis', 'canberra', 'chebyshev', 'correlation', 'mahalanobis', 'seuclidean'];
#metrics=['euclidean'];
for i in metrics:
	print("metric:", i)
	
	train_classification=classify(train_in, train_centres, i);
	train_cmatrix=skm.confusion_matrix(train_out, train_classification);
	norm_train_cmatrix=train_cmatrix/np.sum(train_cmatrix, axis=1)[:, np.newaxis];
	#np.savetxt("tr_c.txt", norm_train_cmatrix, delimiter='&', newline='\\\\\n', fmt='%1.3f');
	print(np.trace(norm_train_cmatrix)/10);
	
	test_classification=classify(test_in, train_centres, i);
	test_cmatrix=skm.confusion_matrix(test_out, test_classification);
	norm_test_cmatrix=test_cmatrix/np.sum(test_cmatrix, axis=1)[:, np.newaxis];
	#np.savetxt("te_c.txt", norm_test_cmatrix, delimiter='&', newline='\\\\\n', fmt='%1.3f');
	print(np.trace(norm_test_cmatrix)/10);