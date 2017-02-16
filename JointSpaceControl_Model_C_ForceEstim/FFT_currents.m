%% FFT Currents, i_actual% Frequency Analysis
close all

% For example, consider the following data x with two component frequencies 
% of differing amplitude and phase buried in noise:

fs = 250;                          % Sample frequency (Hz)
% sample_start = 900;
% sample_end = 2700;

sample_start = 100;
sample_end = length(i_actual_measured.Time);
t = i_actual_measured.Time(sample_start):1/fs:i_actual_measured.Time(sample_end);                % 10 sec sample
i_1 = i_actual_measured.Data(sample_start:sample_end,1);
i_2 = i_actual_measured.Data(sample_start:sample_end,2);
i_3 = i_actual_measured.Data(sample_start:sample_end,3);
i_4 = i_actual_measured.Data(sample_start:sample_end,4);
i_5 = i_actual_measured.Data(sample_start:sample_end,5);
i_6 = i_actual_measured.Data(sample_start:sample_end,6);


%% FFT to analyze currents
m = length(t);          % Window length
n = pow2(nextpow2(m));  % Transform length
n = length(t)
f = (0:n-1)*(fs/n);     % Frequency range
i_1_DFT = fft(i_1,n);           % DFT
i_2_DFT = fft(i_2,n);           % DFT
i_3_DFT = fft(i_3,n);           % DFT
i_4_DFT = fft(i_4,n);           % DFT
i_5_DFT = fft(i_5,n);           % DFT
i_6_DFT = fft(i_6,n);           % DFT

figure, 
subplot(3,2,1), plot(f,abs(i_1_DFT)), title('abs(i_1 DFT)')
subplot(3,2,2), plot(f,abs(i_2_DFT)), title('abs(i_2 DFT)')
subplot(3,2,3), plot(f,abs(i_3_DFT)), title('abs(i_3 DFT)')
subplot(3,2,4), plot(f,abs(i_4_DFT)), title('abs(i_4 DFT)')
subplot(3,2,5), plot(f,abs(i_5_DFT)), title('abs(i_5 DFT)')
subplot(3,2,6), plot(f,abs(i_6_DFT)), title('abs(i_6 DFT)')
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

%% Current 1
N = 10;
fc_low = 5.464;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_i_1 = filter(b,a, i_1);
figure, 
subplot(3,1,1), plot(t, i_1), title('i_1, Original signal')
subplot(3,1,2), plot(t,low_i_1), title('i_1, fc = 5.454')

N = 5;
fc_lower = 1.454;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_i_1 = filter(b,a, i_1);
subplot(3,1,3), plot(t,lower_i_1), title('i_1, fc = 1.454')

%% Current 2
N = 10;
fc_low = 5.464;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_i_2 = filter(b,a, i_2);
figure, 
subplot(3,1,1), plot(t, i_2), title('i_2, Original signal')
subplot(3,1,2), plot(t,low_i_2), title('i_2, fc = 5.454')

N = 5;
fc_lower = 1.454;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_i_2 = filter(b,a, i_2);
subplot(3,1,3), plot(t,lower_i_2), title('i_2, fc = 1.454')

%% Current 3
N = 10;
fc_low = 5.464;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_i_3 = filter(b,a, i_3);
figure, 
subplot(3,1,1), plot(t, i_3), title('i_3, Original signal')
subplot(3,1,2), plot(t,low_i_3), title('i_3, fc = 5.454')

N = 5;
fc_lower = 1.454;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_i_3 = filter(b,a, i_3);
subplot(3,1,3), plot(t,lower_i_3), title('i_3, fc = 1.454')

%% Current 4
N = 10;
fc_low = 5.464;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_i_4 = filter(b,a, i_4);
figure, 
subplot(3,1,1), plot(t, i_4), title('i_4, Original signal')
subplot(3,1,2), plot(t,low_i_4), title('i_4, fc = 5.454')

N = 5;
fc_lower = 1.454;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_i_4 = filter(b,a, i_4);
subplot(3,1,3), plot(t,lower_i_4), title('i_4, fc = 1.454')

%% Current 5
N = 10;
fc_low = 5.464;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_i_5 = filter(b,a, i_5);
figure, 
subplot(3,1,1), plot(t, i_5), title('i_5, Original signal')
subplot(3,1,2), plot(t,low_i_5), title('i_5, fc = 5.454')

N = 5;
fc_lower = 1.454;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_i_5 = filter(b,a, i_5);
subplot(3,1,3), plot(t,lower_i_5), title('i_5, fc = 1.454')

%% Current 6
N = 10;
fc_low = 5.464;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_i_6 = filter(b,a, i_6);
figure, 
subplot(3,1,1), plot(t, i_6), title('i_6, Original signal')
subplot(3,1,2), plot(t,low_i_6), title('i_6, fc = 5.454')

N = 5;
fc_lower = 1.454;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_i_6 = filter(b,a, i_6);
subplot(3,1,3), plot(t,lower_i_6), title('i_6, fc = 1.454')


