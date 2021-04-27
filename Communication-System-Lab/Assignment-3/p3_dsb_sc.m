clc; %clearing console

t = 0:0.01:2;
fm = 3;             
fc = 10;            
Am = 10;
Ac = 4;
fs = 100*fc;      
f = linspace(-fs/2,fs/2,length(t));

% Baseband and carrier signal
m = Am*sin(2*pi*fm*t);
c = Ac*sin(2*pi*fc*t);
y = m.*c;

subplot(321); plot(t, m);
title('Baseband Signal');
ylabel('Amplitude');xlabel('Time index');
subplot(322); plot(t, c);
title('Carrier wave');
ylabel('Amplitude');xlabel('Time index');

subplot(323); plot(t, y);
title('DSBSC WAVE Time');
ylabel('Amplitude');xlabel('Time index');

subplot(324);  plot(f, abs(fftshift(fft(y)))); 
title('DSBSC WAVE Frequency');
ylabel('Amplitude'); xlabel('Frequency index');

%demodulation 
dmt = 2*(y .* c) ./ (Ac*Ac);

h = fir1(40,(0.01 * fc));
z = filter(h,1,dmt);

subplot(325); plot(t, z);
title('Demodulated Time');
ylabel('Amplitude');xlabel('Time index');

subplot(326);  plot(f, abs(fftshift(fft(z)))); 
title('Demodulated Frequency');
ylabel('Amplitude'); xlabel('Frequency index');