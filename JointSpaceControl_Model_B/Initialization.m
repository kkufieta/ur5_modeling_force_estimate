%% INITIALIZATION FILE FOR JointSpaceControl.mdl
% Initializes PD control parameters and initial conditions



%% Create SerialLink for UR5
qn = zeros(1,6);
dh = DenavitHartenberg(qn);
UR5 = SerialLink(dh); % dh = [theta, d, a, alpha]


%% PD control parameters

% % ESTIMATED: (omega_init = 20)
% omega_1 =    43.9545;
% omega_2 =     9.6349;
% omega_3 =    13.0736;
% omega_4 =    19.4183;
% omega_5 =    51.0237;
% omega_6 =    52.3840;
% omega_7 =    46.0450;
% omega_8 =    10.1300;
% omega_9 =    13.5840;
% omega_10 =   21.0031;
% omega_11 =   51.9033;
% omega_12 =   54.2216;

% ESTIMATED: (omega_init = 2)
omega_1 =    33.9094;
omega_2 =     9.5467;
omega_3 =    12.9338;
omega_4 =    12.2111;
omega_5 =    31.3581;
omega_6 =    30.9468;
omega_7 =    34.7433;
omega_8 =    10.0584;
omega_9 =    13.4388;
omega_10 =   12.7900;
omega_11 =   32.0208;
omega_12 =   31.6278;

K_0 = [            omega_1, zeros(1,5); ...
       0,          omega_2, zeros(1,4); ...
       zeros(1,2), omega_3, zeros(1,3); ...
       zeros(1,3), omega_4, zeros(1,2); ...
       zeros(1,4), omega_5, 0; ...
       zeros(1,5), omega_6];

K_1 = [            omega_7, zeros(1,5); ...
       0,          omega_8, zeros(1,4); ...
       zeros(1,2), omega_9, zeros(1,3); ...
       zeros(1,3), omega_10, zeros(1,2); ...
       zeros(1,4), omega_11, 0; ...
       zeros(1,5), omega_12];

run('/Users/kasiunia/Documents/Diplomarbeit/DA_Matlab/JointSpaceControl_Manuf_MCP/load_recorded_data.m')

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
