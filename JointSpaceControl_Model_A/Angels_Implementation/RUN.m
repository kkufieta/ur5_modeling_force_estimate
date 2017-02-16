%% Defining constants
global d_1, d_1 = 0.0892;    % [m]
global a_2, a_2 = -0.425;    % [m]
global a_3, a_3 = -0.39243;  % [m]
global d_4, d_4 = 0.109;     % [m]
global d_5, d_5 = 0.093;     % [m]
global d_6, d_6 = 0.082;     % [m]
%% Create SerialLink for UR5
qn = zeros(1,6);
dh = DenavitHartenberg(qn);
global UR5, UR5 = SerialLink(dh) % dh = [theta, d, a, alpha