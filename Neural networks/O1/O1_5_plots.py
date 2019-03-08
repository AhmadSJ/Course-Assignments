#This code uses network2, it is necessary to adjust the return values of the SGD method
#belonging to network2 into np.arrays(return values) for this code to work. 
import numpy as np
import network
import mnist_loader
import network2
import matplotlib.pyplot as plt

test_in=np.genfromtxt("test_in.csv", delimiter=',');
test_out=np.genfromtxt("test_out.csv", delimiter=',');
train_in=np.genfromtxt("train_in.csv", delimiter=',');
train_out=np.genfromtxt("train_out.csv", delimiter=',');

train_data = [[]]*len(train_out)
test_data = [[]]*len(test_out)
train_evaluation = [[]]*len(train_out)
number = np.empty(10)

for i in range(0, len(train_out)): #shapes the data so that network2 can use it
	x = np.int(train_out[i])
	number = np.zeros(10)
	number[x] = 1
	y = np.reshape(train_in[i], (256,1))
	number = np.reshape(number, (10,1))
	train_data[i] = (y,number)
	train_evaluation[i] = (y, np.int(train_out[i]))
for i in range(0, len(test_out)):
	y = np.reshape(test_in[i], (256,1))
	test_data[i] = (y, np.int(test_out[i]))

epochs = 50 

delta_eta_train = [[]]*7 #saves the plots for different values of x 
delta_eta_test = [[]]*7
for i in range(0,7): # creates accuracy data for different values of x
	print(i)
	x = [200,100,50,20,10,5,1]
	net = network2.Network([256, 30, 10], cost=network2.CrossEntropyCost)
	a = net.SGD(train_data, epochs, x[i], 1, lmbda = 0, evaluation_data=test_data,
	monitor_evaluation_accuracy=True, monitor_training_accuracy=True)
	delta_eta_train[i] = a[3]/1707
	delta_eta_test[i] = a[1]/1000

np.savetxt("test1.txt",np.array(delta_eta_train))
np.savetxt("test2.txt", np.array(delta_eta_test))
a= np.loadtxt("test1.txt")
b= np.loadtxt("test2.txt")
x = np.arange(0,epochs,1)
y= [200,100,50,20,10,5,1]
markers = ['x', '.','o','v','8','s','P']
plt.figure()
for i in range(0,7):
	string = '$m= $' +str(y[i])
	plt.plot(x, a[i], marker = markers[i], markersize = 5,label = string, linewidth = 0.5)
plt.xlabel('epochs')
plt.ylabel('accuracy')
plt.legend(loc = 'lower right')
plt.show()
plt.figure()
for i in range(0,7):
	string = '$m= $' +str(y[i])
	plt.plot(x, b[i], marker = markers[i], markersize = 5,label = string, linewidth = 0.5)
plt.xlabel('epochs')
plt.ylabel('accuracy')
plt.axis(ymin=0,ymax=1)
plt.legend(loc = 'lower right')
plt.show()

