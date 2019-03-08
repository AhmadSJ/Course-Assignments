import numpy as np;
import matplotlib.pyplot as plt;
import sklearn.metrics as skm;

test_in=np.genfromtxt("test_in.csv", delimiter=',');
test_out=np.genfromtxt("test_out.csv", delimiter=',');
train_in=np.genfromtxt("train_in.csv", delimiter=',');
train_out=np.genfromtxt("train_out.csv", delimiter=',');

def get_clouds(data_in, data_out): 
	clouds=[[]]*10;
	for i in range(0, len(data_in)):
		digit=data_out[i];
		digit_index=np.int(digit);
		if clouds[digit_index]==[]:
			clouds[digit_index]=data_in[i];
		else:
			clouds[digit_index]=np.vstack([clouds[digit_index], data_in[i]]);
	return clouds;

train_clouds=get_clouds(train_in, train_out);
test_clouds=get_clouds(test_in, test_out);

class1=4; class2=6 #change classes here

bins = np.linspace(110, 225, 30)
def get_histograms1(class1, class2):
	wspace1 = (train_clouds[class1]*(train_clouds[class1] == -1)).sum(axis = 1)*-1;
	wspace2 = (train_clouds[class2]*(train_clouds[class2] == -1)).sum(axis = 1)*-1;
	plt.hist(wspace2, bins ,alpha = 0.5, facecolor = 'orange',label = 'class 9');
	plt.hist(wspace1, bins , facecolor = 'green', alpha = 0.5, label = 'class 1');
	plt.xlabel('X');
	plt.legend(loc='upper right');

get_histograms1(class1,class2)
plt.show()
#calculates whitespace for each class for the calculation of probabilities
wspace1 = (train_clouds[class1]*(train_clouds[class1] == -1)).sum(axis = 1)*-1;
wspace2 = (train_clouds[class2]*(train_clouds[class2] == -1)).sum(axis = 1)*-1;

values1 = np.histogram(wspace1, bins); #number of samples in each bin
values2 = np.histogram(wspace2, bins);

p1 = [[]]*29; #probabilities for each bin for class 1
p2 = [[]]*29;
nC_1 = np.sum(values1[0]); #number of samples belonging to class 1
nC_2 = np.sum(values2[0]);
nALL = nC_1 + nC_2; # total numer of samples

for i in range(0,29): #calculates the p1 and p2
	box_T =(values1[0][i]+values2[0][i]);
	if box_T == 0:
		p1[i] = 0;
		p2[i] = 0;
	else:
		p1[i] = values1[0][i]/nC_1*nC_1/nALL/(box_T/nALL);
		p2[i] = values2[0][i]/nC_1*nC_1/nALL/(box_T/nALL);	
#determines the whitespace for train and test set for classification
wspace1_train = (train_clouds[class1]*(train_clouds[class1] == -1)).sum(axis = 1)*-1;
wspace2_train = (train_clouds[class2]*(train_clouds[class2] == -1)).sum(axis = 1)*-1;
wspace1_test = (test_clouds[class1]*(test_clouds[class1] == -1)).sum(axis = 1)*-1;
wspace2_test = (test_clouds[class2]*(test_clouds[class2] == -1)).sum(axis = 1)*-1;
pos1_train = np.digitize(wspace1_train, bins)-1; #gives the positions of each box
pos2_train = np.digitize(wspace2_train, bins)-1;
pos1_test = np.digitize(wspace1_test, bins)-1;
pos2_test = np.digitize(wspace2_test, bins)-1;

def classifier(pos): #classifies the images
	classification = [[]]*len(pos);
	for i in range(len(pos)):
		x = pos[i];

		if p1[x] > p2[x]:
			classification[i] = class1;
		else:
			classification[i] = class2;
	return(classification);
	
classification1_train = classifier(pos1_train);
classification2_train = classifier(pos2_train);
classification1_test = classifier(pos1_test);
classification2_test = classifier(pos2_test);

def accuracy(classification, number): #calculates accuracy of classification
	count = 0;
	for i in range(len(classification)):
		if classification[i] == number:
			count += 1;
	return(count/len(classification));
print("Bayes classifier\n");
print("Train set accuracy class1: ", accuracy(classification1_train, class1));
print("Train set accuracy class2: ", accuracy(classification2_train, class2));
print("Test set accuracy class1: ", accuracy(classification1_test, class1));
print("Test set accuracy class2: ", accuracy(classification2_test, class2));