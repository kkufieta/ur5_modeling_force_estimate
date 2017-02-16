%% FFT Acceleration Xyens, XYZ% Frequency Analysis
close all

% For example, consider the following data x with two component frequencies 
% of differing amplitude and phase buried in noise:

fs = 250;                          % Sample frequency (Hz)
sample_start = 900;
% sample_end = 2300;
sample_end = length(i_actual_measured.Time);
t = acceleration_xsens.Time(sample_start):1/fs:i_actual_measured.Time(sample_end);                % 10 sec sample
acc_Xsens_X = acceleration_xsens.Data(sample_start:sample_end,1);
acc_Xsens_Y = acceleration_xsens.Data(sample_start:sample_end,2);
acc_Xsens_Z = acceleration_xsens.Data(sample_start:sample_end,3);


%% FFT to analyze currents
m = length(t);          % Window length
n = pow2(nextpow2(m));  % Transform length
n = length(t)
f = (0:n-1)*(fs/n);     % Frequency range
acc_1_DFT = fft(acc_Xsens_X,n);           % DFT
acc_2_DFT = fft(acc_Xsens_Y,n);           % DFT
acc_3_DFT = fft(acc_Xsens_Z,n);           % DFT

figure, 
subplot(3,1,1), plot(f,abs(acc_1_DFT)), title('abs(acc_1 DFT)')
subplot(3,1,2), plot(f,abs(acc_2_DFT)), title('abs(acc_2 DFT)')
subplot(3,1,3), plot(f,abs(acc_3_DFT)), title('abs(acc_3 DFT)')

% i_1_power = i_1_DFT.*conj(i_1_DFT)/n;   % Power of the DFT
% i_2_power = i_2_DFT.*conj(i_2_DFT)/n;   % Power of the DFT
% i_3_power = i_3_DFT.*conj(i_3_DFT)/n;   % Power of the DFT
% i_4_power = i_4_DFT.*conj(i_4_DFT)/n;   % Power of the DFT
% i_5_power = i_5_DFT.*conj(i_5_DFT)/n;   % Power of the DFT
% i_6_power = i_6_DFT.*conj(i_6_DFT)/n;   % Power of the DFT

% i_1_DFT_0 = fftshift(i_1_DFT);          % Rearrange y values
% i_2_DFT_0 = fftshift(i_2_DFT);          % Rearrange y values
% i_3_DFT_0 = fftshift(i_3_DFT);          % Rearrange y values
% i_4_DFT_0 = fftshift(i_4_DFT);          % Rearrange y values
% i_5_DFT_0 = fftshift(i_5_DFT);          % Rearrange y values
% i_6_DFT_0 = fftshift(i_6_DFT);          % Rearrange y values
% f0 = (-n/2:n/2-1)*(fs/n);  % 0-centered frequency range
% i_1_power0 = i_1_DFT_0.*conj(i_1_DFT_0)/n;   % 0-centered power
% i_2_power0 = i_2_DFT_0.*conj(i_2_DFT_0)/n;   % 0-centered power
% i_3_power0 = i_3_DFT_0.*conj(i_3_DFT_0)/n;   % 0-centered power
% i_4_power0 = i_4_DFT_0.*conj(i_4_DFT_0)/n;   % 0-centered power
% i_5_power0 = i_5_DFT_0.*conj(i_5_DFT_0)/n;   % 0-centered power
% i_6_power0 = i_6_DFT_0.*conj(i_6_DFT_0)/n;   % 0-centered power
% nextpow2 finds the exponent of the next power of two greater than or 
% equal to the window length (ceil(log2(m))), and pow2 computes the power. 
% Using a power of two for the transform length optimizes the FFT algorithm, 
% though in practice there is usually little difference in execution time from using n = m.
% 

% i_1_IFT = ifft(i_1_DFT);
% i_2_IFT = ifft(i_2_DFT);
% i_3_IFT = ifft(i_3_DFT);
% i_4_IFT = ifft(i_4_DFT);
% i_5_IFT = ifft(i_5_DFT);
% i_6_IFT = ifft(i_6_DFT);


% To visualize the DFT, plots of abs(y), abs(y).^2, and log(abs(y)) are all common. 
% A plot of power versus frequency is called a periodogram:
% figure
% plot(f,abs(y))
% title('abs(y)')
% figure
% plot(f,abs(y).^2)
% title('abs(y).^2')
% figure
% plot(f,log(abs(y)))
% title('log(abs(y))')

% figure, plot(f,abs(i_1_DFT)), title('abs(i_1 DFT)')
% figure, plot(f,i_1_power), xlabel('Frequency (Hz)'), ylabel('i_1 Power'), title('{\bf Periodogram}')
% figure, plot(f0,i_1_power0), xlabel('Frequency (Hz)'), ylabel('i_1 Power'), title('{\bf 0-Centered Periodogram}')
% figure, plot(t,i_1_IFT(1:length(t)))

%% Filter parameters

fc_high = 7;
fc_low = 5.464;
fc_lower = 1.454;
%% acc_Xsens_X
N = 8;
[b,a] = butter(N, fc_high/(fs/2),'low');
high_acc_Xsens_X = filter(b,a, acc_Xsens_X);
figure, 
subplot(4,1,1), plot(t, acc_Xsens_X), title('acc_Xsens_X, Original signal')
subplot(4,1,2), plot(t,high_acc_Xsens_X), title('acc_Xsens_X, fc = 13.56')

N = 10;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_acc_Xsens_X = filter(b,a, acc_Xsens_X);
subplot(4,1,3), plot(t,low_acc_Xsens_X), title('acc_Xsens_X, fc = 5.454')

N = 5;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_acc_Xsens_X = filter(b,a, acc_Xsens_X);
subplot(4,1,4), plot(t,lower_acc_Xsens_X), title('acc_Xsens_X, fc = 1.454')

%% acc_Xsens_Y
N = 8;
[b,a] = butter(N, fc_high/(fs/2),'low');
high_acc_Xsens_Y = filter(b,a, acc_Xsens_Y);
figure, 
subplot(4,1,1), plot(t, acc_Xsens_Y), title('acc_Xsens_Y, Original signal')
subplot(4,1,2), plot(t,high_acc_Xsens_Y), title('acc_Xsens_Y, fc = 13.56')

N = 10;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_acc_Xsens_Y = filter(b,a, acc_Xsens_Y);
subplot(4,1,3), plot(t,low_acc_Xsens_Y), title('acc_Xsens_Y, fc = 5.454')

N = 5;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_acc_Xsens_Y = filter(b,a, acc_Xsens_Y);
subplot(4,1,4), plot(t,lower_acc_Xsens_Y), title('acc_Xsens_Y, fc = 1.454')

%% acc_Xsens_Z
N = 8;
[b,a] = butter(N, fc_high/(fs/2),'low');
high_acc_Xsens_Z = filter(b,a, acc_Xsens_Z);
figure, 
subplot(4,1,1), plot(t, acc_Xsens_Z), title('acc_Xsens_Z, Original signal')
subplot(4,1,2), plot(t,high_acc_Xsens_Z), title('acc_Xsens_Z, fc = 13.56')

N = 10;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_acc_Xsens_Z = filter(b,a, acc_Xsens_Z);
subplot(4,1,3), plot(t,low_acc_Xsens_Z), title('acc_Xsens_Z, fc = 5.454')

N = 5;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_acc_Xsens_Z = filter(b,a, acc_Xsens_Z);
subplot(4,1,4), plot(t,lower_acc_Xsens_Z), title('acc_Xsens_Z, fc = 1.454')


