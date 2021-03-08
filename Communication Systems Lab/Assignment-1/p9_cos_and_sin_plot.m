clc; %clearing console

n = input("Enter n: ");
t = -n*pi:0.0001:n*pi;
x = cos(t);
y = sin(t);

%same plot
figure(1);
plot(t, x); hold on;
plot(t, y);
xlim([-n*pi n*pi]);

%same window but different plots
figure(2);
subplot(121),plot(t,x);
subplot(122),plot(t,y);
xlim([-n*pi n*pi]);