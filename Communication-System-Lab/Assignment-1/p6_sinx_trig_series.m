clc; %clearing console

x = input("Enter x in radians to compute sin(x): ");
sinx = 0;

for i = 0:3
   sinx = sinx + (-1)^i*x^(2*i+1)/factorial(2*i+1); 
end

disp("sin(x) = ");
disp(sinx);