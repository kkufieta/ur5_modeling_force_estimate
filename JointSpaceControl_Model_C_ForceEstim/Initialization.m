%% INITIALIZATION FILE FOR JointSpaceControl.mdl
% Initializes PD control parameters and initial conditions



%% Create SerialLink for UR5
qn = zeros(1,6);
dh = DenavitHartenberg(qn);
UR5 = SerialLink(dh); % dh = [theta, d, a, alpha]



%% PD control parameters

% Natural frequency omega. 
% Could be e.g. 4, 8 or 12 (critically damped 2nd order system)
% The steady state error decreases for increasing omega.
% omega = 4;
% % omega = 0.1;
% K_0 = omega^2*eye(6,6);
% K_1 = 2*omega*eye(6,6);


% Estimated omega (from slower measurement data):
% omega = 2.1424;

% Estimated omega (when max velocity is used, i.e. new measurement data):
% omega_P = 2.2736;

% Estimated omega_P & omega_D (with fast dynamics, estimate 2 parameters):
% omega_P = 8.8517;
% omega_D = 40.1322;
% K_0 = omega_P^2*eye(6,6);
% K_1 = 2*omega_D*eye(6,6);

% Estimated omega_P & omega_D for both large and small joint
% (with fast dynamics, estimate 4 parameters):
% omega_P_large = 7.9477;
% omega_P_small = 7.7658;
% omega_D_large = 32.9445;
% omega_D_small = 30.5790;
% K_0 = [omega_P_large^2*eye(3,3), zeros(3,3); zeros(3,3),omega_P_small^2*eye(3,3)];
% K_1 = [2*omega_D_large*eye(3,3), zeros(3,3); zeros(3,3),2*omega_D_small*eye(3,3)];



%% Estimated 8 PD parameters - Constrained acceleration [15 15 15 25 25 25]
% Control parameters for large joints (estimated separately)
% omega_P_1 = 7.5046;
% omega_D_1 = 28.6208;
% omega_P_2 = 6.5619;
% omega_D_2 = 21.9111;
% omega_P_3 = 10.2280;
% omega_D_3 = 56.6301;
% 
% % Control parameters for small joints (assumed to be the same)
% omega_P_small = 9.1428;
% omega_D_small = 42.2920;
% 
% K0_11 = [omega_P_1^2, 0, 0; 0, omega_P_2^2, 0; 0, 0, omega_P_3^2];    
% K_0 = [K0_11, zeros(3,3); zeros(3,3),omega_P_small^2*eye(3,3)];
% K1_11 = [omega_D_1*2, 0, 0; 0, omega_D_2*2, 0; 0, 0, omega_D_3*2];
% K_1 = [K1_11, zeros(3,3); zeros(3,3),2*omega_D_small*eye(3,3)];

%% Estimated 8 PD parameters - Constrained acceleration [15 15 15 25 25 25]
% Control parameters for large joints (estimated separately)
% omega_P_1 = 8.4841;
% omega_D_1 = 36.5366;
% omega_P_2 = 6.6640;
% omega_D_2 = 22.5504;
% omega_P_3 = 4.9684;
% omega_D_3 = 12.5987;
% 
% % Control parameters for small joints (assumed to be the same)
% omega_P_small = 8.7739;
% omega_D_small = 38.9344;
% 
% K0_11 = [omega_P_1^2, 0, 0; 0, omega_P_2^2, 0; 0, 0, omega_P_3^2];    
% K_0 = [K0_11, zeros(3,3); zeros(3,3),omega_P_small^2*eye(3,3)];
% K1_11 = [omega_D_1*2, 0, 0; 0, omega_D_2*2, 0; 0, 0, omega_D_3*2];
% K_1 = [K1_11, zeros(3,3); zeros(3,3),2*omega_D_small*eye(3,3)];
   

%% My wild guess
omega_P_1 = 8.4841;
omega_D_1 = 36.5366;
omega_P_2 = 6.6640;
omega_D_2 = 22.5504;
omega_P_3 = 10.2280;
omega_D_3 = 56.6301;

% Control parameters for small joints (assumed to be the same)
omega_P_small = 8.7739;
omega_D_small = 38.9344;


%% Estimated parameters for this model (ran PEM on the Best_Inertia_Model)
% omega_P_1 = 8.1008;
% omega_D_1 =  28.6761;
% omega_P_2 = 3.3734;
% omega_D_2 = 5.9190;
% omega_P_3 = 17.8049;
% omega_D_3 = 217.2802;
% 
% % % Control parameters for small joints (assumed to be the same)
% omega_P_small = 7.0729;
% omega_D_small = 25.5102;

K0_11 = [omega_P_1^2, 0, 0; 0, omega_P_2^2, 0; 0, 0, omega_P_3^2];    
K_0 = [K0_11, zeros(3,3); zeros(3,3),omega_P_small^2*eye(3,3)];
K1_11 = [omega_D_1*2, 0, 0; 0, omega_D_2*2, 0; 0, 0, omega_D_3*2];
K_1 = [K1_11, zeros(3,3); zeros(3,3),2*omega_D_small*eye(3,3)];


%% Just another parameter estimation, with lsqlin
% K0_11 =  140.5174;
% K0_22 =         0;
% K0_33 =   76.1344;
% K0_44 =         0;
% K0_55 =         0;
% K0_66 =  117.1643;
% 
% K1_11 =         0;
% K1_22 =    1.1619;
% K1_33 =         0;
% K1_44 =         0;
% K1_55 =    0.1980;
% K1_66 =    1.2323;
% 
% K_0 = [K0_11, zeros(1,5); 0, K0_22, zeros(1,4); zeros(1,2), K0_33, zeros(1,3); zeros(1,3), K0_44, zeros(1,2); zeros(1,4), K0_55, 0; zeros(1,5), K0_66];
% K_1 = [K1_11, zeros(1,5); 0, K1_22, zeros(1,4); zeros(1,2), K1_33, zeros(1,3); zeros(1,3), K1_44, zeros(1,2); zeros(1,4), K1_55, 0; zeros(1,5), K1_66];

run('/Users/kasiunia/Documents/Diplomarbeit/DA_Matlab/JointSpaceControl_ForceEstim/load_recorded_data.m')

%% Initial conditions

% UR5 joint positions
q_0 = q_actual.signals.values(1,:);        % position in degrees
% q_end = [0 -90 0 -90 0 0];  % position in degrees

% UR5 joint velocities
dq_0 = qd_actual.signals.values(1,:);        % position in degrees
% dq_end = [0 0 0 0 0 0];  % position in degrees

%% Limits
% 3 big joints, 3 small joints
q_max =  2*pi*ones(1,6);        % [rad]
q_min = -2*pi*ones(1,6);        % [rad]
v_max = 3.4*ones(1,6);          % [rad/sec]
% a_max = [15 15 15 25 25 25];    % [rad/sec/sec]
a_max = [27 27 27 27 27 27];    % [rad/sec/sec]
torque_max = [150 150 150 28 28 28];

%% Trajectory planning

% -------------------------------------------------------------------------
% Trajectory that is applied to the robot
% -------------------------------------------------------------------------
% load('RecordedUR5Data/Movement_No1/mat_files/q_reference.mat')
% load('RecordedUR5Data/Movement_No1/mat_files/dq_reference.mat')
% load('RecordedUR5Data/Movement_No1/mat_files/tcp_vector.mat')

% % -------------------------------------------------------------------------
% % General trajectory to test model:
% % -------------------------------------------------------------------------
% t_start = 0;
% t_end = 50;
% % Generate trajectories (in degrees)
% [s1, sd1, sdd1] = tpoly(q_0(1),q_end(1),t_end-t_start);
% [s2, sd2, sdd2] = tpoly(q_0(2),q_end(2),t_end-t_start);
% [s3, sd3, sdd3] = tpoly(q_0(3),q_end(3),t_end-t_start);
% [s4, sd4, sdd4] = tpoly(q_0(4),q_end(4),t_end-t_start);
% [s5, sd5, sdd5] = tpoly(q_0(5),q_end(5),t_end-t_start);
% [s6, sd6, sdd6] = tpoly(q_0(6),q_end(6),t_end-t_start);
% 
% time = [t_start:t_end-1];
% s = struct('values',[s1, s2, s3, s4, s5, s6]*2*pi/360);             % in rad
% sd = struct('values',[sd1, sd2, sd3, sd4, sd5, sd6]*2*pi/360);      % in rad/s
% sdd = struct('values',[sdd1, sdd2, sdd3, sdd4, sdd5, sdd6]*2*pi/360);% in rad/s^2
% 
% q_d = struct('time',time,'signals', s);
% dq_d = struct('time',time,'signals', sd);
% ddq_d = struct('time',time,'signals', sdd);
% 
% clear('s1', 'sd1', 'sdd1', 's2', 'sd2', 'sdd2', 's3', 'sd3', 'sdd3', ...
%       's4', 'sd4', 'sdd4', 's5', 'sd5', 'sdd5', 's6', 'sd6', 'sdd6');

