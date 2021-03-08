clc; %clearing console

mat1 = randi([0, 100], 3); %generating random matrix
disp("Matrix 1: ");
disp(mat1);

mat2 = randi([0, 100], 3); %generating random matrix
disp("Matrix 2: ");
disp(mat2);

disp("Normal Matrix Multiplication (mat1 * mat2):")
disp(mat1*mat2);

disp("Element By Element Matrix Multiplication (mat1 .* mat2):")
disp(mat1.*mat2);