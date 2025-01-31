% clear everything
clc;
close all;
clear all;

amplitude = 5;
time      = 0:0.001:1;

carrier_frequency = input("Carrier Frequency: "); % eg. 25
pulse_frequency   = input("Pulse Frequency: ");   % eg. 5

% subplot(m, n, p) is a function that divides the page into a grid
% m, n is size of grid in row, col
% p is the selected position to display the next plot on

x = amplitude.*sin(2 * pi * carrier_frequency * time) + (amplitude / 2);
subplot(3, 1, 1);
plot(time, x);
title("Carrier");
grid on;

u = amplitude/2.*square(2 * pi * pulse_frequency * time) + (amplitude / 2);
subplot(3, 1, 2);
plot(time, u);
title("Square Pulses");
grid on;

v = x.*u;
subplot(3, 1, 3);
plot(time, v);
title("ASK Signal");
grid on;
