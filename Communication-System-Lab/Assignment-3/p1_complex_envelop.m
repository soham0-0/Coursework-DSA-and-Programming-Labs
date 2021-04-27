clc; %clearing console

n = 0:0.2:100;
y = n.*exp(n.*1j);

subplot(211);
[up,lo] = envelope(real(y),300);
plot(n, real(y), '--', n ,up, '-', n, lo, '-');
xlabel('t')
ylabel('Signal')

subplot(212), plot(n,angle(y));
xlabel('t')
ylabel('Phase angle')