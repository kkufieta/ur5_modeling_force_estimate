% Compare accelerometer measurements vs. modelled
close all

xmin = 0; xmax = 35; ymin = -1000; ymax = 1000;

% run('/Users/kasiunia/Documents/Diplomarbeit/DA_Matlab/JointSpaceControl_ForceEstim/FFT_currents.m'), close all
% lower_i_1, lower_i_2, lower_i_3, lower_i_4, lower_i_5, lower_i_6

sample_start = 100;
sample_end = length(i_actual_measured.Time);
%% Filter and Map currents to torques
f_hz = 1/4;


% figure('Name', 'i actual measured vs. torque estimated w friction vs. position')
% subplot(2,3,1), plot3(i_actual_measured.Data(sample_start:sample_end,1), estimated_torque_w_friction.Data(sample_start:sample_end,1), joint_variables_q_measured.Data(sample_start:sample_end,1)), xlabel('current_1'), ylabel('torque_1'), zlabel('position_1'), grid on
% subplot(2,3,2), plot3(i_actual_measured.Data(sample_start:sample_end,2), estimated_torque_w_friction.Data(sample_start:sample_end,2), joint_variables_q_measured.Data(sample_start:sample_end,2)), xlabel('current_2'), ylabel('torque_2'), zlabel('position_2'), grid on
% subplot(2,3,3), plot3(i_actual_measured.Data(sample_start:sample_end,3), estimated_torque_w_friction.Data(sample_start:sample_end,3), joint_variables_q_measured.Data(sample_start:sample_end,3)), xlabel('current_3'), ylabel('torque_3'), zlabel('position_3'), grid on
% subplot(2,3,4), plot3(i_actual_measured.Data(sample_start:sample_end,4), estimated_torque_w_friction.Data(sample_start:sample_end,4), joint_variables_q_measured.Data(sample_start:sample_end,4)), xlabel('current_4'), ylabel('torque_4'), zlabel('position_4'), grid on
% subplot(2,3,5), plot3(i_actual_measured.Data(sample_start:sample_end,5), estimated_torque_w_friction.Data(sample_start:sample_end,5), joint_variables_q_measured.Data(sample_start:sample_end,5)), xlabel('current_5'), ylabel('torque_5'), zlabel('position_5'), grid on
% subplot(2,3,6), plot3(i_actual_measured.Data(sample_start:sample_end,6), estimated_torque_w_friction.Data(sample_start:sample_end,6), joint_variables_q_measured.Data(sample_start:sample_end,6)), xlabel('current_6'), ylabel('torque_6'), zlabel('position_6'), grid on

% figure('Name', 'i actual measured vs. torque estimated w friction')
% subplot(2,3,1), plot(i_actual_measured.Data(sample_start:sample_end,1), estimated_torque_w_friction.Data(sample_start:sample_end,1)), xlabel('current_1'), ylabel('torque_1')
% subplot(2,3,2), plot(i_actual_measured.Data(sample_start:sample_end,2), estimated_torque_w_friction.Data(sample_start:sample_end,2)), xlabel('current_2'), ylabel('torque_2')
% subplot(2,3,3), plot(i_actual_measured.Data(sample_start:sample_end,3), estimated_torque_w_friction.Data(sample_start:sample_end,3)), xlabel('current_3'), ylabel('torque_3')
% subplot(2,3,4), plot(i_actual_measured.Data(sample_start:sample_end,4), estimated_torque_w_friction.Data(sample_start:sample_end,4)), xlabel('current_4'), ylabel('torque_4')
% subplot(2,3,5), plot(i_actual_measured.Data(sample_start:sample_end,5), estimated_torque_w_friction.Data(sample_start:sample_end,5)), xlabel('current_5'), ylabel('torque_5')
% subplot(2,3,6), plot(i_actual_measured.Data(sample_start:sample_end,6), estimated_torque_w_friction.Data(sample_start:sample_end,6)), xlabel('current_6'), ylabel('torque_6')

% figure('Name', 'i actual filtered vs. position')
% subplot(2,3,1), plot(lower_i_1, joint_variables_q_measured.Data(sample_start:sample_end,1)), xlabel('filtered_current_1'), ylabel('position_1')
% subplot(2,3,2), plot(lower_i_2, joint_variables_q_measured.Data(sample_start:sample_end,2)), xlabel('filtered_current_2'), ylabel('position_2')
% subplot(2,3,3), plot(lower_i_3, joint_variables_q_measured.Data(sample_start:sample_end,3)), xlabel('filtered_current_3'), ylabel('position_3')
% subplot(2,3,4), plot(lower_i_4, joint_variables_q_measured.Data(sample_start:sample_end,4)), xlabel('filtered_current_4'), ylabel('position_4')
% subplot(2,3,5), plot(lower_i_5, joint_variables_q_measured.Data(sample_start:sample_end,5)), xlabel('filtered_current_5'), ylabel('position_5')
% subplot(2,3,6), plot(lower_i_6, joint_variables_q_measured.Data(sample_start:sample_end,6)), xlabel('filtered_current_6'), ylabel('position_6')

figure('Name', 'i actual measured vs. position')
subplot(2,3,1), plot(i_actual_measured.Data(sample_start:sample_end,1), joint_variables_q_measured.Data(sample_start:sample_end,1)), xlabel('current_1'), ylabel('position_1')
subplot(2,3,2), plot(i_actual_measured.Data(sample_start:sample_end,2), joint_variables_q_measured.Data(sample_start:sample_end,2)), xlabel('current_2'), ylabel('position_2')
subplot(2,3,3), plot(i_actual_measured.Data(sample_start:sample_end,3), joint_variables_q_measured.Data(sample_start:sample_end,3)), xlabel('current_3'), ylabel('position_3')
subplot(2,3,4), plot(i_actual_measured.Data(sample_start:sample_end,4), joint_variables_q_measured.Data(sample_start:sample_end,4)), xlabel('current_4'), ylabel('position_4')
subplot(2,3,5), plot(i_actual_measured.Data(sample_start:sample_end,5), joint_variables_q_measured.Data(sample_start:sample_end,5)), xlabel('current_5'), ylabel('position_5')
subplot(2,3,6), plot(i_actual_measured.Data(sample_start:sample_end,6), joint_variables_q_measured.Data(sample_start:sample_end,6)), xlabel('current_6'), ylabel('position_6')

% figure('Name', 'torque_estimated_w_fricition vs. position')
% subplot(2,3,1), plot(estimated_torque_w_friction.Data(sample_start:sample_end,1), joint_variables_q_measured.Data(sample_start:sample_end,1)), xlabel('torque_1'), ylabel('position_1')
% subplot(2,3,2), plot(estimated_torque_w_friction.Data(sample_start:sample_end,2), joint_variables_q_measured.Data(sample_start:sample_end,2)), xlabel('torque_2'), ylabel('position_2')
% subplot(2,3,3), plot(estimated_torque_w_friction.Data(sample_start:sample_end,3), joint_variables_q_measured.Data(sample_start:sample_end,3)), xlabel('torque_3'), ylabel('position_3')
% subplot(2,3,4), plot(estimated_torque_w_friction.Data(sample_start:sample_end,4), joint_variables_q_measured.Data(sample_start:sample_end,4)), xlabel('torque_4'), ylabel('position_4')
% subplot(2,3,5), plot(estimated_torque_w_friction.Data(sample_start:sample_end,5), joint_variables_q_measured.Data(sample_start:sample_end,5)), xlabel('torque_5'), ylabel('position_5')
% subplot(2,3,6), plot(estimated_torque_w_friction.Data(sample_start:sample_end,6), joint_variables_q_measured.Data(sample_start:sample_end,6)), xlabel('torque_6'), ylabel('position_6')

% figure('Name', 'torque_modelled vs. position')
% subplot(2,3,1), plot(torque_mod.Data(sample_start:sample_end,1), joint_variables_q_measured.Data(sample_start:sample_end,1)), xlabel('torque_1'), ylabel('position_1')
% subplot(2,3,2), plot(torque_mod.Data(sample_start:sample_end,2), joint_variables_q_measured.Data(sample_start:sample_end,2)), xlabel('torque_2'), ylabel('position_2')
% subplot(2,3,3), plot(torque_mod.Data(sample_start:sample_end,3), joint_variables_q_measured.Data(sample_start:sample_end,3)), xlabel('torque_3'), ylabel('position_3')
% subplot(2,3,4), plot(torque_mod.Data(sample_start:sample_end,4), joint_variables_q_measured.Data(sample_start:sample_end,4)), xlabel('torque_4'), ylabel('position_4')
% subplot(2,3,5), plot(torque_mod.Data(sample_start:sample_end,5), joint_variables_q_measured.Data(sample_start:sample_end,5)), xlabel('torque_5'), ylabel('position_5')
% subplot(2,3,6), plot(torque_mod.Data(sample_start:sample_end,6), joint_variables_q_measured.Data(sample_start:sample_end,6)), xlabel('torque_6'), ylabel('position_6')



figure('Name', 'i actual measured vs. torque modelled w friction')
subplot(2,3,1), plot(i_actual_measured.Data(sample_start:sample_end,1), torque_w_friction.Data(sample_start:sample_end,1)), xlabel('current_1'), ylabel('torque_1')
subplot(2,3,2), plot(i_actual_measured.Data(sample_start:sample_end,2), torque_w_friction.Data(sample_start:sample_end,2)), xlabel('current_2'), ylabel('torque_2')
subplot(2,3,3), plot(i_actual_measured.Data(sample_start:sample_end,3), torque_w_friction.Data(sample_start:sample_end,3)), xlabel('current_3'), ylabel('torque_3')
subplot(2,3,4), plot(i_actual_measured.Data(sample_start:sample_end,4), torque_w_friction.Data(sample_start:sample_end,4)), xlabel('current_4'), ylabel('torque_4')
subplot(2,3,5), plot(i_actual_measured.Data(sample_start:sample_end,5), torque_w_friction.Data(sample_start:sample_end,5)), xlabel('current_5'), ylabel('torque_5')
subplot(2,3,6), plot(i_actual_measured.Data(sample_start:sample_end,6), torque_w_friction.Data(sample_start:sample_end,6)), xlabel('current_6'), ylabel('torque_6')

figure('Name', 'i actual measured vs. torque modelled')
subplot(2,3,1), plot(i_actual_measured.Data(sample_start:sample_end,1), torque_mod.Data(sample_start:sample_end,1)), xlabel('current_1'), ylabel('torque_1')
subplot(2,3,2), plot(i_actual_measured.Data(sample_start:sample_end,2), torque_mod.Data(sample_start:sample_end,2)), xlabel('current_2'), ylabel('torque_2')
subplot(2,3,3), plot(i_actual_measured.Data(sample_start:sample_end,3), torque_mod.Data(sample_start:sample_end,3)), xlabel('current_3'), ylabel('torque_3')
subplot(2,3,4), plot(i_actual_measured.Data(sample_start:sample_end,4), torque_mod.Data(sample_start:sample_end,4)), xlabel('current_4'), ylabel('torque_4')
subplot(2,3,5), plot(i_actual_measured.Data(sample_start:sample_end,5), torque_mod.Data(sample_start:sample_end,5)), xlabel('current_5'), ylabel('torque_5')
subplot(2,3,6), plot(i_actual_measured.Data(sample_start:sample_end,6), torque_mod.Data(sample_start:sample_end,6)), xlabel('current_6'), ylabel('torque_6')


% figure('Name', 'torque modelled w friction vs. position')
% subplot(2,3,1), plot(torque_w_friction.Data(sample_start:sample_end,1), joint_variables_q_measured.Data(sample_start:sample_end,1)), xlabel('torque_1'), ylabel('position_1')
% subplot(2,3,2), plot(torque_w_friction.Data(sample_start:sample_end,2), joint_variables_q_measured.Data(sample_start:sample_end,2)), xlabel('torque_2'), ylabel('position_2')
% subplot(2,3,3), plot(torque_w_friction.Data(sample_start:sample_end,3), joint_variables_q_measured.Data(sample_start:sample_end,3)), xlabel('torque_3'), ylabel('position_3')
% subplot(2,3,4), plot(torque_w_friction.Data(sample_start:sample_end,4), joint_variables_q_measured.Data(sample_start:sample_end,4)), xlabel('torque_4'), ylabel('position_4')
% subplot(2,3,5), plot(torque_w_friction.Data(sample_start:sample_end,5), joint_variables_q_measured.Data(sample_start:sample_end,5)), xlabel('torque_5'), ylabel('position_5')
% subplot(2,3,6), plot(torque_w_friction.Data(sample_start:sample_end,6), joint_variables_q_measured.Data(sample_start:sample_end,6)), xlabel('torque_6'), ylabel('position_6')

% Ts = 0.008;
% np = 0;     % Number of poles
% data = iddata(estimated_torque_w_friction.Data,i_actual_measured.Data,Ts)
% sys = tfest(data,np)

% Ts = 0.016;
% np = 0;     % Number of poles
% nz = 0;
% data_1 = iddata(torque_w_friction.Data(:,1),filtered_currents(:,1),Ts)
% iodelay_1 = 67*Ts/2;
% sys_1 = tfest(data_1,np,nz,iodelay_1)
% sys_1 = tfest(data_1,np)
% % Less filtered
% currents_to_torque_map = [[ -0.2239   ,    0.05002    , -0.03987   , -0.3986     , -0.0546        , 0.6273      ]; ...
%                         [   -6.263    ,    9.698      , 0.4817     , -3.252      , -16.56         , -0.6452     ]; ...
%                         [   -2.012    ,    1.228      , 4.562      , -9.661      , 2.051          , 11.45       ]; ...
%                         [   -0.2898   ,    0.2027     , -0.07557   , 0.8068      , 0.1004         , -0.2999     ]; ...
%                         [   -0.03776  ,    0.02472    , 0.004042   , 0.2034      , 0.08746        , -0.3879     ]; ...
%                         [   -9.579e-06,    4.482e-06  , -1.78e-07  , -2.423e-05  , -3.548e-05     , 3.755e-05   ]];

% Better filtered
% currents_to_torque_map = [[ -0.2341   ,    0.05191    , -0.03781   , -0.4271     , -0.06599       , 0.6769      ]; ...
%                         [   -6.459    ,    9.758      , 0.3892     , -3.577      , -17.37         , -0.3951     ]; ...
%                         [   -2.123    ,    1.238      , 4.768      , -10.28      , 1.986          , 12.56       ]; ...
%                         [   -0.294    ,    0.2037     , -0.08516   , 0.8454      , 0.1009         , -0.3163     ]; ...
%                         [   -0.03583  ,    0.02453    , 0.0009552  , 0.2137      , 0.0899         , -0.4194     ]; ...
%                         [   -1.008e-05,    4.555e-06  , 1.178e-07  , -2.533e-05  , -3.599e-05     , 4.169e-05   ]];

% Accelerometer estimated torque vs. currents (both almost unfiltered)
% currents_to_torque_map = [[ 0.2006, 2.086, -1.88, -0.2174, -0.06665, -8.286e-06     ]; ...
%                         [   0.007647, 8.319, 3.048, 0.2082, 0.04435, 6.663e-07   ]; ...
%                         [   0.09936, 5.086, 1.554, 0.1095, 0.02058, -2.465e-06     ]; ...
%                         [   0.1698, 1.608, -2.777, 0.3914, 0.03394, 5.654e-06     ]; ...
%                         [   0.5058, 3.711, 5.775, -1.435, -0.2287, 5.468e-06   ]; ...
%                         [   -1.558, -0.6296, 2.91, 0.2812, 0.09377, -1.437e-06  ]];
                    
%% Estimate Force
% mapped_torques = currents_to_torque_map*filtered_disturbed_currents';
% mapped_torques = mapped_torques'
% torque_difference = mapped_torques - torque_mod.Data;

%% BEST so far

tor_1 = 7.5* i_actual_measured.Data(sample_start:sample_end,1) - 0.61;
tor_2 = 6.8* i_actual_measured.Data(sample_start:sample_end,2) + 16;
tor_3 = 7.1* i_actual_measured.Data(sample_start:sample_end,3) + 4.5;
tor_4 = 2.8* i_actual_measured.Data(sample_start:sample_end,4) + 0.84;
tor_5 = 3.2* i_actual_measured.Data(sample_start:sample_end,5) + 0.064;
tor_6 = 3.4* i_actual_measured.Data(sample_start:sample_end,6) * 0.099;
tor = [tor_1, tor_2, tor_3, tor_4, tor_5, tor_6];


%% Force estimation with torque_w_friction
torque_difference = tor - torque_w_friction.Data(sample_start:sample_end,:);

%% FFT to analyze torque_difference
fs = 250;       
t = i_actual_measured.Time(sample_start):1/fs:i_actual_measured.Time(sample_end);                % 10 sec sample
m = length(t);          % Window length
n = pow2(nextpow2(m));  % Transform length
n = length(t);
f = (0:n-1)*(fs/n);     % Frequency range
torque_difference_DFT = fft(torque_difference,n);           % DFT

% figure('Name', 'abs(torque_difference DFT), torque_mod')
% plot(f,abs(torque_difference_DFT)), title('abs(torque_difference DFT)')

%% Filter parameters

fc_high = 7;
fc_low = 5.464;
fc_lower = 1.454;

N = 10;
[b,a] = butter(N, fc_high/(fs/2),'low');
high_torque_difference = filter(b,a, torque_difference);
figure('Name', 'torque_difference, torque_mod')
subplot(4,1,1), plot(t, torque_difference), title('torque_difference, Original signal'), legend('1','2','3','4','5','6')
subplot(4,1,2), plot(t,high_torque_difference), title('torque_difference, fc = 7'), legend('1','2','3','4','5','6')

N = 10;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_torque_difference = filter(b,a, torque_difference);
subplot(4,1,3), plot(t,low_torque_difference), title('torque_difference, fc = 5.464'), legend('1','2','3','4','5','6')

N = 5;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_torque_difference = filter(b,a, torque_difference);
subplot(4,1,4), plot(t,lower_torque_difference), title('torque_difference, fc = 1.454'), legend('1','2','3','4','5','6')


force_estim_kathi = zeros(length(high_torque_difference),6);
Jacobian = J_kathi.Data;    
for i = 1:length(high_torque_difference)
    force_estim_kathi(i,:) = (Jacobian(:,:,i)')\high_torque_difference(i,:)';
end

% figure('Name', 'Estimated Force based on currents, torque_mod')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')
% axis([xmin xmax ymin ymax])


good_force_estim_kathi = zeros(length(lower_torque_difference),6);
Jacobian = J_kathi.Data;    
for i = 1:length(lower_torque_difference)
    good_force_estim_kathi(i,:) = (Jacobian(:,:,i)')\lower_torque_difference(i,:)';
end

% force_estim_kathi = zeros(length(lower_torque_difference),6);
% Jacobian = J_kathi.Data;    
% for i = 1:length(lower_torque_difference)
%     force_estim_kathi(i,:) = inv(inv(Jacobian(:,:,i))')*((Jacobian(:,:,i)')\lower_torque_difference(i,:)');
% end

% figure('Name', 'Estimated Force based on currents, torque_w_friction')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')


figure('Name', 'Compare Estimated Forces (tor-mod_torque_w_friction) vs. Force estimation from UR5')
subplot(3,2,1), plot(t,good_force_estim_kathi(:,1)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,1),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,1),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,2), plot(t,good_force_estim_kathi(:,2)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,2),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,2),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,3), plot(t,good_force_estim_kathi(:,3)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,3),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,3),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,4), plot(t,good_force_estim_kathi(:,4)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,4),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,4),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,5), plot(t,good_force_estim_kathi(:,5)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,5),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,5),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,6), plot(t,good_force_estim_kathi(:,6)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,6),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,6),'g'), legend('estimated','UR5','force sensor')
                
figure('Name', 'Compare Estimated Forces (tor-mod_torque_w_friction) vs. Force estimation from UR5')
subplot(3,2,1), plot(t,good_force_estim_kathi(:,1)), hold on,
                plot(t, force_sensor_measured.Data(sample_start:sample_end,1),'g'), legend('estimated','force sensor')
subplot(3,2,2), plot(t,good_force_estim_kathi(:,2)), hold on,
                plot(t, force_sensor_measured.Data(sample_start:sample_end,2),'g'), legend('estimated','force sensor')
subplot(3,2,3), plot(t,good_force_estim_kathi(:,3)), hold on,
                plot(t, force_sensor_measured.Data(sample_start:sample_end,3),'g'), legend('estimated','force sensor')
subplot(3,2,4), plot(t,good_force_estim_kathi(:,4)), hold on,
                plot(t, force_sensor_measured.Data(sample_start:sample_end,4),'g'), legend('estimated','force sensor')
subplot(3,2,5), plot(t,good_force_estim_kathi(:,5)), hold on,
                plot(t, force_sensor_measured.Data(sample_start:sample_end,5),'g'), legend('estimated','force sensor')
subplot(3,2,6), plot(t,good_force_estim_kathi(:,6)), hold on,
                plot(t, force_sensor_measured.Data(sample_start:sample_end,6),'g'), legend('estimated','force sensor')
                

                
%% Force estimation with torque_modelled
torque_difference = tor - torque_mod.Data(sample_start:sample_end,:);

%% FFT to analyze torque_difference
fs = 250;       
t = i_actual_measured.Time(sample_start):1/fs:i_actual_measured.Time(sample_end);                % 10 sec sample
m = length(t);          % Window length
n = pow2(nextpow2(m));  % Transform length
n = length(t)
f = (0:n-1)*(fs/n);     % Frequency range
torque_difference_DFT = fft(torque_difference,n);           % DFT

% figure('Name', 'abs(torque_difference DFT), torque_mod')
% plot(f,abs(torque_difference_DFT)), title('abs(torque_difference DFT)')

%% Filter parameters

fc_high = 7;
fc_low = 5.464;
fc_lower = 1.454;

N = 10;
[b,a] = butter(N, fc_high/(fs/2),'low');
high_torque_difference = filter(b,a, torque_difference);
figure('Name', 'torque_difference, torque_mod')
subplot(4,1,1), plot(t, torque_difference), title('torque_difference, Original signal'), legend('1','2','3','4','5','6')
subplot(4,1,2), plot(t,high_torque_difference), title('torque_difference, fc = 7'), legend('1','2','3','4','5','6')

N = 10;
[b,a] = butter(N, fc_low/(fs/2),'low');
low_torque_difference = filter(b,a, torque_difference);
subplot(4,1,3), plot(t,low_torque_difference), title('torque_difference, fc = 5.464'), legend('1','2','3','4','5','6')

N = 5;
[b,a] = butter(N, fc_lower/(fs/2),'low');
lower_torque_difference = filter(b,a, torque_difference);
subplot(4,1,4), plot(t,lower_torque_difference), title('torque_difference, fc = 1.454'), legend('1','2','3','4','5','6')


force_estim_kathi = zeros(length(high_torque_difference),6);
Jacobian = J_kathi.Data;    
for i = 1:length(high_torque_difference)
    force_estim_kathi(i,:) = (Jacobian(:,:,i)')\high_torque_difference(i,:)';
end

% figure('Name', 'Estimated Force based on currents, torque_mod')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')
% axis([xmin xmax ymin ymax])


bad_force_estim_kathi = zeros(length(lower_torque_difference),6);
Jacobian = J_kathi.Data;    
for i = 1:length(lower_torque_difference)
    bad_force_estim_kathi(i,:) = (Jacobian(:,:,i)')\lower_torque_difference(i,:)';
end


% force_estim_kathi = zeros(length(lower_torque_difference),6);
% Jacobian = J_kathi.Data;    
% for i = 1:length(lower_torque_difference)
%     force_estim_kathi(i,:) = inv(inv(Jacobian(:,:,i))')*((Jacobian(:,:,i)')\lower_torque_difference(i,:)');
% end

% figure('Name', 'Estimated Force based on currents, torque_mod')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')
% 
                
figure('Name', 'Compare Estimated Forces (tor - torque_mod) vs. Force estimation from UR5')
subplot(3,2,1), plot(t,bad_force_estim_kathi(:,1)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,1),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,1),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,2), plot(t,bad_force_estim_kathi(:,2)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,2),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,2),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,3), plot(t,bad_force_estim_kathi(:,3)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,3),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,3),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,4), plot(t,bad_force_estim_kathi(:,4)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,4),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,4),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,5), plot(t,bad_force_estim_kathi(:,5)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,5),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,5),'g'), legend('estimated','UR5','force sensor')
subplot(3,2,6), plot(t,bad_force_estim_kathi(:,6)), hold on,
                plot(t, force_ur5_modelled.Data(sample_start:sample_end,6),'r')
                plot(t, force_sensor_measured.Data(sample_start:sample_end,6),'g'), legend('estimated','UR5','force sensor')



%% Force estimation with torque_estimated
% 
% torque_difference = tor - estimated_torque_w_friction.Data(sample_start:sample_end,:);
% 
% %% FFT to analyze torque_difference
% fs = 250;       
% t = acceleration_xsens.Time(sample_start):1/fs:i_actual_measured.Time(sample_end);                % 10 sec sample
% m = length(t);          % Window length
% n = pow2(nextpow2(m));  % Transform length
% n = length(t)
% f = (0:n-1)*(fs/n);     % Frequency range
% torque_difference_DFT = fft(torque_difference,n);           % DFT
% 
% figure('Name', 'abs(torque_difference DFT), torque_est') 
% plot(f,abs(torque_difference_DFT)), title('abs(torque_difference DFT)')
% 
% %% Filter parameters
% 
% fc_high = 7;
% fc_low = 5.464;
% fc_lower = 1.454;
% 
% N = 10;
% [b,a] = butter(N, fc_high/(fs/2),'low');
% high_torque_difference = filter(b,a, torque_difference);
% figure('Name', 'torque_difference, torque_est') 
% subplot(4,1,1), plot(t, torque_difference), title('torque_difference, Original signal'), legend('1','2','3','4','5','6')
% subplot(4,1,2), plot(t,high_torque_difference), title('torque_difference, fc = 7'), legend('1','2','3','4','5','6')
% 
% N = 10;
% [b,a] = butter(N, fc_low/(fs/2),'low');
% low_torque_difference = filter(b,a, torque_difference);
% subplot(4,1,3), plot(t,low_torque_difference), title('torque_difference, fc = 5.464'), legend('1','2','3','4','5','6')
% 
% N = 5;
% [b,a] = butter(N, fc_lower/(fs/2),'low');
% lower_torque_difference = filter(b,a, torque_difference);
% subplot(4,1,4), plot(t,lower_torque_difference), title('torque_difference, fc = 1.454'), legend('1','2','3','4','5','6')
% 
% 
% force_estim_kathi = zeros(length(high_torque_difference),6)
% Jacobian = J_kathi.Data;    
% for i = 1:length(high_torque_difference)
%     force_estim_kathi(i,:) = Jacobian(:,:,i)'\high_torque_difference(i,:)';
% end
% 
% figure('Name', 'Estimated Force based on currents, torque_est')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')
% % axis([xmin xmax ymin ymax])
% 
% 
% force_estim_kathi = zeros(length(lower_torque_difference),6)
% Jacobian = J_kathi.Data;    
% temp_Jacob = Jacobian(:,:,1);
% for i = 1:length(lower_torque_difference)
%     if det(Jacobian(:,:,i)) == 0
%         force_estim_kathi(i,:) = temp_Jacob'\torque_difference(i,:)';
%     else
%         force_estim_kathi(i,:) = Jacobian(:,:,i)'\torque_difference(i,:)';
%     end
%     temp_Jacob = Jacobian(:,:,i);
% end
% 
% figure('Name', 'Estimated Force based on currents, torque_est')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')
% 
% figure('Name', 'Compare Estimated Forces (torque est) vs. Force estimation from UR5')
% subplot(3,2,1), plot(t,force_estim_kathi(:,1)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,1),'r'), legend('estimated','UR5')
% subplot(3,2,2), plot(t,force_estim_kathi(:,2)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,2),'r'), legend('estimated','UR5')
% subplot(3,2,3), plot(t,force_estim_kathi(:,3)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,3),'r'), legend('estimated','UR5')
% subplot(3,2,4), plot(t,force_estim_kathi(:,4)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,4),'r'), legend('estimated','UR5')
% subplot(3,2,5), plot(t,force_estim_kathi(:,5)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,5),'r'), legend('estimated','UR5')
% subplot(3,2,6), plot(t,force_estim_kathi(:,6)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,6),'r'), legend('estimated','UR5')
                
% %% Force estimation with torque_estimated
% 
% % torque_difference = i_actual_measured.Data(sample_start:sample_end,:) - [torque_mod.Data(sample_start:sample_end,1:3)*0.13, torque_mod.Data(sample_start:sample_end,4:6)*0.14];
% torque_difference = i_actual_measured.Data(sample_start:sample_end,:) - torque_mod.Data(sample_start:sample_end,:);
% 
% %% FFT to analyze torque_difference
% fs = 250;       
% t = acceleration_xsens.Time(sample_start):1/fs:i_actual_measured.Time(sample_end);                % 10 sec sample
% m = length(t);          % Window length
% n = pow2(nextpow2(m));  % Transform length
% n = length(t)
% f = (0:n-1)*(fs/n);     % Frequency range
% torque_difference_DFT = fft(torque_difference,n);           % DFT
% 
% figure('Name', 'abs(torque_difference DFT), torque_est') 
% plot(f,abs(torque_difference_DFT)), title('abs(torque_difference DFT)')
%                 
% %% Filter parameters
% 
% fc_high = 7;
% fc_low = 5.464;
% fc_lower = 1.454;
% 
% N = 10;
% [b,a] = butter(N, fc_high/(fs/2),'low');
% high_torque_difference = filter(b,a, torque_difference);
% figure('Name', 'torque_difference, torque_est') 
% subplot(4,1,1), plot(t, torque_difference), title('torque_difference, Original signal'), legend('1','2','3','4','5','6')
% subplot(4,1,2), plot(t,high_torque_difference), title('torque_difference, fc = 7'), legend('1','2','3','4','5','6')
% 
% N = 10;
% [b,a] = butter(N, fc_low/(fs/2),'low');
% low_torque_difference = filter(b,a, torque_difference);
% subplot(4,1,3), plot(t,low_torque_difference), title('torque_difference, fc = 5.464'), legend('1','2','3','4','5','6')
% 
% N = 5;
% [b,a] = butter(N, fc_lower/(fs/2),'low');
% lower_torque_difference = filter(b,a, torque_difference);
% subplot(4,1,4), plot(t,lower_torque_difference), title('torque_difference, fc = 1.454'), legend('1','2','3','4','5','6')
% 
% 
% force_estim_kathi = zeros(length(high_torque_difference),6)
% Jacobian = J_kathi.Data;    
% for i = 1:length(high_torque_difference)
%     force_estim_kathi(i,:) = Jacobian(:,:,i)'\high_torque_difference(i,:)';
% end
% 
% figure('Name', 'Estimated Force based on currents, torque_est')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')
% % axis([xmin xmax ymin ymax])
% 
% 
% force_estim_kathi = zeros(length(lower_torque_difference),6);
% Jacobian = J_kathi.Data;    
% temp_Jacob = Jacobian(:,:,1);
% for i = 1:length(lower_torque_difference)
%     if det(Jacobian(:,:,i)) <= -0.2 
%         force_estim_kathi(i,:) = temp_Jacob'\torque_difference(i,:)';
%     elseif det(Jacobian(:,:,i)) >= 0.2
%         force_estim_kathi(i,:) = temp_Jacob'\torque_difference(i,:)';
%     else
%         force_estim_kathi(i,:) = Jacobian(:,:,i)'\torque_difference(i,:)';
%     end
%     temp_Jacob = Jacobian(:,:,i);
% end
% 
% figure('Name', 'Estimated Force based on currents, torque_est')
% plot(t, force_estim_kathi), title('Estimated Force based on currents'), legend('1','2','3','4','5','6')
% 
% figure('Name', 'Compare Estimated Forces (torque est) vs. Force estimation from UR5')
% subplot(3,2,1), plot(t,force_estim_kathi(:,1)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,1),'r'), legend('estimated','UR5')
% subplot(3,2,2), plot(t,force_estim_kathi(:,2)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,2),'r'), legend('estimated','UR5')
% subplot(3,2,3), plot(t,force_estim_kathi(:,3)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,3),'r'), legend('estimated','UR5')
% subplot(3,2,4), plot(t,force_estim_kathi(:,4)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,4),'r'), legend('estimated','UR5')
% subplot(3,2,5), plot(t,force_estim_kathi(:,5)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,5),'r'), legend('estimated','UR5')
% subplot(3,2,6), plot(t,force_estim_kathi(:,6)), hold on,
%                 plot(t, force_ur5_modelled.Data(sample_start:sample_end,6),'r'), legend('estimated','UR5')
% 
