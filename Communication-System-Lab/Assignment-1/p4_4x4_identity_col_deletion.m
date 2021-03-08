clc; %clearing console

mat = eye(4);

disp("Identity Matrix of 4x4:");
disp(mat);

mat(:, 2) = [];

disp("After Removing 2nd Column:");
disp(mat);