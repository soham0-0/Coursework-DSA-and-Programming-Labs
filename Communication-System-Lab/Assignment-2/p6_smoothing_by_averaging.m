clc; %clearing console

% generating noisy signal
t = 0:0.01:3;
y = 0.5*exp(0.7*t);
noise = rand(1, length(t));
yNoisy = y + noise;

% smoothing by average
M = input("Choose length of filter: ");
num = ones(1,M);
ySmoothed = filter(num, 1, yNoisy)/M;

%ploting
subplot(211);
p1 = plot(t, y, t, noise, t, yNoisy);
legend("Uncorrupted Signal", "Noise", "Corrupted Signal");
set(p1, {'LineWidth'}, {1;1;1});

subplot(212);
p2 = plot(t, yNoisy, t, ySmoothed);
legend("Corrupted Signal", "Smoothed Signal");
set(p2, {'LineWidth'}, {1;2});