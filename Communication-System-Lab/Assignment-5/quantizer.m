clc; %clearing console

[x,fs] = audioread('clip.wav');
disp('Playing Original Clip...');
%sound(x, fs);
subplot(5, 2, [1 2]);
plot(x);
ylim([-1 1]);
title('Original Waveform');

for n = 1:8
    %pause(2.5);
    [q, mse] = quantize(x, n);
    disp(['Quantized Clip for N = ' num2str(n)]);
    disp('Playing...');
    %sound(q, fs);
    disp(['Mean Square error = ' num2str(mse)]);
    subplot(5, 2, n + 2); 
    plot(q);
    ylim([-1 1]);
    title(['N = ' num2str(n)]);
end

function [X, mse] = quantize(x, N)
    difference = max(x) - min(x);
    delta = difference / (2 ^ N);
    X = round(x./delta) .* delta;
    error = abs(X - x);
    mse = mean(error.^2);
end