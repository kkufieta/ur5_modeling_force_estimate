% Compare accelerometer measurements vs. modelled
close all

%% Filter measurements
%% Filter acceleration
% acceleration: 17 periods per second
f_hz = 1/2;
% To convert from Hz to normalized frequency, multiply the frequency in Hz
% by two and divide by the sampling frequency." --> f(norm) = f(Hz)*2/F(sampl)
f_sample = 1/0.08;

f_norm = f_hz*2/f_sample;

N = 100;   % FIR filter order
d = fdesign.lowpass('N,Fc',N,f_norm);
Hd = design(d,'window');
filtered_acceleration = filter(Hd,acceleration_xsens.Data);
% 
% figure, plot(acceleration_xsens.Time, acceleration_xsens.Data)
figure
subplot(3,1,1), plot(acceleration_xsens), title('Acceleration measurements')
subplot(3,1,2), plot(acceleration_xsens.Time, filtered_acceleration), title('Filtered acceleration')
subplot(3,1,3), plot(ddX_linear_plus_g.Time, ddX_linear_plus_g.Data), title('modelled acceleration'), 


% %% Filter angular acceleration
% % acceleration: 17 periods per second
% f_hz = 1/2;
% % To convert from Hz to normalized frequency, multiply the frequency in Hz
% % by two and divide by the sampling frequency." --> f(norm) = f(Hz)*2/F(sampl)
% f_sample = 1/0.08;
% 
% f_norm = f_hz*2/f_sample;
% 
% N = 100;   % FIR filter order
% d = fdesign.lowpass('N,Fc',N,f_norm);
% Hd = design(d,'window');
% filtered_ang_acceleration = filter(Hd,angular_acceleration_xsens.Data);
% % 
% % figure, plot(acceleration_xsens.Time, acceleration_xsens.Data)
% figure('Name', 'filter angular acceleration')
% subplot(2,1,1), plot(angular_acceleration_xsens)
% subplot(2,1,2), plot(angular_acceleration_xsens.Time, filtered_ang_acceleration)
%% Filter gyro
% acceleration: 17 periods per second
f_hz = 1/5;
% To convert from Hz to normalized frequency, multiply the frequency in Hz
% by two and divide by the sampling frequency." --> f(norm) = f(Hz)*2/F(sampl)
f_sample = 1/0.08;

f_norm = f_hz*2/f_sample;

N = 100;   % FIR filter order
d = fdesign.lowpass('N,Fc',N,f_norm);
Hd = design(d,'window');
filtered_gyro = filter(Hd,gyro_xsens.Data);
% 
% figure, plot(acceleration_xsens.Time, acceleration_xsens.Data)
figure
subplot(3,1,1), plot(gyro_xsens), title('Gyro measurements')
subplot(3,1,2), plot(gyro_xsens.Time, filtered_gyro), title('Filtered gyro')
subplot(3,1,3), plot(dX_angular), title('modelled angular velocity'), 

%% Compare filtered measurements with modelled values

figure
subplot(2,1,1), plot(ddX_linear), title('modelled acceleration'), 
subplot(2,1,2), plot(acceleration_xsens.Time, filtered_acceleration), title('measured acceleration')              

figure
subplot(2,1,1), plot(dX_angular), title('modelled angular velocity'), 
subplot(2,1,2), plot(gyro_xsens.Time, filtered_gyro), title('measured gyro')

figure
subplot(3,1,1), plot(ddX_linear.Time, ddX_linear.Data(:,1),...
                     acceleration_xsens.Time, filtered_acceleration(:,1))
                legend('modelled acc', 'measured acc')
                title('measured vs. modelled acceleration - X')
subplot(3,1,2), plot(ddX_linear.Time, ddX_linear.Data(:,2),...
                     acceleration_xsens.Time, filtered_acceleration(:,2))
                title('measured vs. modelled acceleration - Y')
subplot(3,1,3), plot(ddX_linear.Time, ddX_linear.Data(:,3),...
                     acceleration_xsens.Time, filtered_acceleration(:,3))
                title('measured vs. modelled acceleration - Z')


figure
subplot(3,2,1), plot(ddX_linear.Time, ddX_linear.Data(:,1))
                title('modelled acc - X')
subplot(3,2,2), plot(acceleration_xsens.Time, filtered_acceleration(:,1))
                title('measured acc - X')
subplot(3,2,3), plot(ddX_linear.Time, ddX_linear.Data(:,2))
                title('modelled acc - Y')
subplot(3,2,4), plot(gyro_xsens.Time, filtered_acceleration(:,2))
                title('measured acc - Y')
subplot(3,2,5), plot(ddX_linear.Time, ddX_linear.Data(:,3))
                title('modelled acc - Z')
subplot(3,2,6), plot(acceleration_xsens.Time, filtered_acceleration(:,3))
                title('measured acc - Z')
                
figure
subplot(3,2,1), plot(dX_angular.Time, dX_angular.Data(:,1))
                title('modelled gyro - X')
subplot(3,2,2), plot(gyro_xsens.Time, filtered_gyro(:,1))
                title('measured gyro - X')
subplot(3,2,3), plot(dX_angular.Time, dX_angular.Data(:,2))
                title('modelled gyro - Y')
subplot(3,2,4), plot(gyro_xsens.Time, filtered_gyro(:,2))
                title('measured gyro - Y')
subplot(3,2,5), plot(dX_angular.Time, dX_angular.Data(:,3))
                title('modelled gyro - Z')
subplot(3,2,6), plot(gyro_xsens.Time, filtered_gyro(:,3))
                title('measured gyro - Z')

                
%% Calculate angular acceleration
h = 0.008;       %step size
filtered_ang_acceleration = diff(filtered_gyro)/h;   % angular acceleration
figure('Name', 'Angular acceleration')
% subplot(3,1,1), plot(ddX_angular.Time, ddX_angular.Data(:,1),...
%                      angular_acceleration_xsens.Time(1:(end-1)), filtered_ang_acceleration(:,1))
%                 legend('modelled angular acc', 'measured d_dt gyro')
%                 title('measured vs. modelled acceleration - RX')
% subplot(3,1,2), plot(ddX_angular.Time, ddX_angular.Data(:,2),...
%                      angular_acceleration_xsens.Time(1:(end-1)), filtered_ang_acceleration(:,2))
%                 title('measured vs. modelled acceleration - RY')
% subplot(3,1,3), plot(ddX_angular.Time, ddX_angular.Data(:,3),...
%                      angular_acceleration_xsens.Time(1:(end-1)), filtered_ang_acceleration(:,3))
%                 title('measured vs. modelled acceleration - RZ')
% figure
subplot(3,2,1), plot(ddX_angular.Time, ddX_angular.Data(:,1))
                title('modelled angular acc - RX')
subplot(3,2,2), plot(angular_acceleration_xsens.Time(1:(end-1)), filtered_ang_acceleration(:,1))
                title('measured angular acc - RX')
subplot(3,2,3), plot(ddX_angular.Time, ddX_angular.Data(:,2))
                title('modelled angular acc - RY')
subplot(3,2,4), plot(angular_acceleration_xsens.Time(1:(end-1)), filtered_ang_acceleration(:,2))
                title('measured angular acc - RY')
subplot(3,2,5), plot(ddX_angular.Time, ddX_angular.Data(:,3))
                title('modelled angular acc - RZ')
subplot(3,2,6), plot(angular_acceleration_xsens.Time(1:(end-1)), filtered_ang_acceleration(:,3))
                title('measured angular acc - RZ')

                
%% Compare filtered measurements with modelled values - Corrected Gravity!

figure
subplot(2,1,1), plot(ddX_linear_plus_g), title('modelled acceleration_plus_g'), 
subplot(2,1,2), plot(acceleration_xsens.Time, filtered_acceleration), title('measured acceleration')              

figure
subplot(3,1,1), plot(ddX_linear_plus_g.Time, ddX_linear_plus_g.Data(:,1),...
                     acceleration_xsens.Time, filtered_acceleration(:,1))
                legend('modelled acc_plus_g', 'measured acc')
                title('measured vs. modelled_plus_g acceleration - X')
subplot(3,1,2), plot(ddX_linear_plus_g.Time, ddX_linear_plus_g.Data(:,2),...
                     acceleration_xsens.Time, filtered_acceleration(:,2))
                legend('modelled acc_plus_g', 'measured acc')
                title('measured vs. modelled_plus_g acceleration - Y')
subplot(3,1,3), plot(ddX_linear_plus_g.Time, ddX_linear_plus_g.Data(:,3),...
                     acceleration_xsens.Time, filtered_acceleration(:,3))
                legend('modelled acc_plus_g', 'measured acc')
                title('measured vs. modelled_plus_g acceleration - Z')