function dh = DenavitHartenberg(q)
% DenavitHartenberg returns a matrix dh wich has one row per joint and 
% each row is [theta d a alpha]. Joints are assumed revolute.
q_1 = q(1);
q_2 = q(2);
q_3 = q(3);
q_4 = q(4);
q_5 = q(5);
q_6 = q(6);

global d_1
global a_2
global a_3
global d_4
global d_5
global d_6


dh_1 = [q_1, d_1,    0,  pi/2];
dh_2 = [q_2,   0, -a_2,     0];
dh_3 = [q_3,   0, -a_3,     0];
dh_4 = [q_4, d_4,    0,  pi/2];
dh_5 = [q_5, d_5,    0, -pi/2];
dh_6 = [q_6, d_6,    0,     0];

dh = [dh_1; dh_2; dh_3; dh_4; dh_5; dh_6];