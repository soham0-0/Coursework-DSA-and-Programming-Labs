% Project:- High Density Bipolar Coding (HDB3) Illustration
% Submitted By:- 
%   Name: Soham Pal
%   Enrollment Number: 510819035
%   Department: Information Technology
%   College: Indian Institute of Engineering Science and Technology, Shibpur

clc; %clearing console

% Conversion Rules:

% If the number of 1's is odd use 000V
% If previous sign is negative 000-
odd_negative = [0 0 0 -1];
% Otherwise 000+
odd_positive = [0 0 0 1];

% If the number of 1's is even use B00V
% If previous sign is negative use +00+
even_negative = [1 0 0 1];
% Otherwise -00-
even_positive = [-1 0 0 -1];

%Input binary code
xn = input("Enter bitstream array: "); %[1 1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0];
yn = xn;
num = 0;	%variable to count the 1s and determine if they are odd or even

%AMI Code Generation
for k = 1:length(xn)
    if xn(k) == 1
        num = num + 1;                               
        if num/2 == fix(num/2)	%Condition for even numbers of 1s
            yn(k) = -1;
        else
            yn(k) = 1;          %Condition for odd numbers of 1s
        end
    end
end
                                                
num = 0;	%count of continuous 0s to change the code by 000V or B00V
yh = yn;
sign = 0;
count = 0;  %count of 1s in between sequences to decide 000V or B00V
for k = 1:length(yn)
    if yn(k) == 0
        num = num + 1;                                      %0s counter increment
        if num == 4                                         %Checks for 4 continuous zeros to make the change
            if count/2 == fix(count/2)
                if sign == 1
                    yh(k-3:k) = even_positive;
                else
                    yh(k-3:k) = even_negative;
                end
                yh(k+1:length(yn)) = -1*yh(k+1:length(yn)); %Alternate the signs of the 1s after detecting a sign change.                
            else 
                if sign == 1
                    yh(k-3:k) = odd_positive;
                else
                    yh(k-3:k) = odd_negative;    
                end
            end
            sign = yh(k);                                   %Save the sign of violation
            count = 0;                                      %Resets the 1s counter
            num = 0;                                        %Resets the 0s counter
        end
    else
        sign = yh(k);                                       %Saving the sign of 1s
        num = 0;                                            %Resets the 0s counter
        count = count + 1;                                  %1s counter increment
    end
end                                         

%Part to decode the signal.
decode = yh;	%Variable to decode HDB3
sign = 0;       %Variable to save the sign of the 1s
for k = 1:length(yh)
    if yh(k) ~= 0
        if sign == yh(k)                %if there are two 1s with the same sign, these are
            decode(k-3:k) = [0 0 0 0];	%changed by 0000
        end
        sign = yh(k);                   %It keeps the sign of the 1s
    end
end
decode = abs(decode);                   %Absolute value to turn negative 1's to positive

%Plotting
subplot(411);
stairs((0:length(xn)-1), xn);
axis([0 length(xn) -2 2]);
title('Transmitted Binary Code');
grid on;

subplot(412);
stairs([0:length(xn)-1], yn);
axis([0 length(xn) -2 2]);
title('Encoded in AMI');
grid on;

subplot(413);
stairs((0:length(xn)-1), yh);
axis([0 length(xn) -2 2]);
title('Encoded in HDB3');
grid on;

subplot(414);
stairs((0:length(xn)-1), decode);
axis([0 length(xn) -2 2]);
title('Decoded Binary Code');
grid on;