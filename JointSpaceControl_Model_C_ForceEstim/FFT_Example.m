% Frequency Analysis
close all

% For example, consider the following data x with two component frequencies 
% of differing amplitude and phase buried in noise:

fs = 125;                          % Sample frequency (Hz)
t = 0:0.008:acceleration_xsens.Time(end);                % 10 sec sample
ddX = acceleration_xsens.Data(:,1);
% Use fft to compute the DFT y and its power:

m = length(ddX);          % Window length
n = pow2(nextpow2(m));  % Transform length
y = fft(ddX,n);           % DFT
f = (0:n-1)*(fs/n);     % Frequency range
power = y.*conj(y)/n;   % Power of the DFT
% nextpow2 finds the exponent of the next power of two greater than or 
% equal to the window length (ceil(log2(m))), and pow2 computes the power. 
% Using a power of two for the transform length optimizes the FFT algorithm, 
% though in practice there is usually little difference in execution time from using n = m.
% 
% % To visualize the DFT, plots of abs(y), abs(y).^2, and log(abs(y)) are all common. 
% % A plot of power versus frequency is called a periodogram:
% figure
% plot(f,abs(y))
% title('abs(y)')
% figure
% plot(f,abs(y).^2)
% title('abs(y).^2')
% figure
% plot(f,log(abs(y)))
% title('log(abs(y))')
% 
% figure
% plot(f,power)
% xlabel('Frequency (Hz)')
% ylabel('Power')
% title('{\bf Periodogram}')
% y0 = fftshift(y);          % Rearrange y values
% f0 = (-n/2:n/2-1)*(fs/n);  % 0-centered frequency range
% power0 = y0.*conj(y0)/n;   % 0-centered power
% 
% figure
% plot(f0,power0)
% xlabel('Frequency (Hz)')
% ylabel('Power')
% title('{\bf 0-Centered Periodogram}')

%% Torque estimated 1
fs = 125;                          % Sample frequency (Hz)
p = joint_variables_q_measured.Data(:,1);                % 10 sec sample
tor1 = torque_est.Data(:,1);
tor2 = torque_est.Data(:,2);
i1 = i_actual_measured.Data(:,1);
i2 = i_actual_measured.Data(:,2);
% Use fft to compute the DFT y and its power:

m = length(tor1);          % Window length
n = pow2(nextpow2(m));  % Transform length
y = fft(tor1,n);           % DFT
f = (0:n-1)*(fs/n);     % Frequency range
power = y.*conj(y)/n;   % Power of the DFT

figure
plot(f,abs(y))
title('abs(tor1)')
figure
plot(f,abs(y).^2)
title('abs(y).^2')
figure
plot(f,log(abs(y)))
title('log(abs(y))')

figure
plot(f,power)
xlabel('Frequency (Hz)')
ylabel('Power')
title('{\bf Periodogram}')
y0 = fftshift(y);          % Rearrange y values
f0 = (-n/2:n/2-1)*(fs/n);  % 0-centered frequency range
power0 = y0.*conj(y0)/n;   % 0-centered power

figure
plot(f0,power0)
xlabel('Frequency (Hz)')
ylabel('Power')
title('{\bf 0-Centered Periodogram}')

%% Torque estimated 2

m = length(tor2);          % Window length
n = pow2(nextpow2(m));  % Transform length
y = fft(tor2,n);           % DFT
f = (0:n-1)*(fs/n);     % Frequency range
power = y.*conj(y)/n;   % Power of the DFT

figure
plot(f,abs(y))
title('abs(tor2)')

figure
plot(f,power)
xlabel('Frequency (Hz)')
ylabel('Power')
title('{\bf Periodogram}')
y0 = fftshift(y);          % Rearrange y values
f0 = (-n/2:n/2-1)*(fs/n);  % 0-centered frequency range
power0 = y0.*conj(y0)/n;   % 0-centered power

%% Current 1
% m = length(i1);          % Window length
% n = pow2(nextpow2(m));  % Transform length
% y = fft(i1,n);           % DFT
% f = (0:n-1)*(fs/n);     % Frequency range
% power = y.*conj(y)/n;   % Power of the DFT
% 
% figure
% plot(f,abs(y))
% title('abs(i1)')
% %% Current 2
% 
% m = length(i2);          % Window length
% n = pow2(nextpow2(m));  % Transform length
% y = fft(i2,n);           % DFT
% f = (0:n-1)*(fs/n);     % Frequency range
% power = y.*conj(y)/n;   % Power of the DFT
% 
% figure
% plot(f,abs(y))
% title('abs(i2)')