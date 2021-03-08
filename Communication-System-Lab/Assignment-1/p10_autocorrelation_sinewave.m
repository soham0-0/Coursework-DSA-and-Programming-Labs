clc; %clearing console

N = 1024;
f1 = 1;
FS = 200; 
n = 0:N-1;
x = sin(2*pi*f1*n/FS); 

[xc,lags] = xcorr(x);
tau = lags*1/FS;

plot(tau,xc);