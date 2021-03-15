clc; %clearing console

% generating noisy signal
t = 0:0.1:10;
y = 5*cos(2*pi*t);
noise = 3*(rand(1, length(t)) - 1/2);
yNoisy = y + noise;

% smoothing by average
ySmoothed = smoothdata(yNoisy);

%ploting
subplot(211);
p1 = plot(t, y, t, noise, t, yNoisy);
legend("Uncorrupted Signal", "Noise", "Corrupted Signal");
set(p1, {'LineWidth'}, {1;1;1});

subplot(212);
p2 = plot(t, yNoisy, t, ySmoothed);
legend("Corrupted Signal", "Smoothed Signal");
set(p2, {'LineWidth'}, {1;1});