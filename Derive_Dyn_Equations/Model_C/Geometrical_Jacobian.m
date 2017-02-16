% JACOBIAN Calculate the Jacobian of the UR5.
% clc, clear all, close all
%% Denavit Hartenberg Parameters.
% theta_1, theta_2, theta_3, theta_4, theta_5, theta_6 are variables.

d_1 = 0.0892; d_2 = 0; d_3 = 0; d_4 = 0.109; d_5 = 0.093; d_6 = 0.082;
a_1 = 0; a_2 = -0.425; a_3 = -0.39243; a_4 = 0; a_5 = 0; a_6 = 0;
alpha_1 = (1/2)*pi; alpha_2 = 0; alpha_3 = 0; alpha_4 = (1/2)*pi; 
alpha_5 = -(1/2)*pi; alpha_6 = 0;
syms theta_1 theta_2 theta_3 theta_4 theta_5 theta_6;

%% Transformation Matrices A1...A6.
% They describe the transformation from one link to the next link.
syms theta alpha a d;
A(theta, alpha, a, d) =...
    [cos(theta), -sin(theta)*cos(alpha), sin(theta)*sin(alpha), a*cos(theta); ...
     sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(theta); ...
     0, sin(alpha), cos(alpha), d; ...
     0, 0, 0, 1];
A1(theta_1) = A(theta_1, alpha_1, a_1, d_1);
A2(theta_2) = A(theta_2, alpha_2, a_2, d_2); 
A3(theta_3) = A(theta_3, alpha_3, a_3, d_3); 
A4(theta_4) = A(theta_4, alpha_4, a_4, d_4); 
A5(theta_5) = A(theta_5, alpha_5, a_5, d_5); 
A6(theta_6) = A(theta_6, alpha_6, a_6, d_6);

%% Transformation Matrices T1...T6.
% They describe the transformation from the base to the respective link.
T1(theta_1) = A1(theta_1);
T2(theta_1, theta_2) = T1(theta_1)*A2(theta_2);
T3(theta_1, theta_2, theta_3) = T2(theta_1, theta_2)*A3(theta_3);
T4(theta_1, theta_2, theta_3, theta_4) = ...
    T3(theta_1, theta_2, theta_3)*A4(theta_4);
T5(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
    T4(theta_1, theta_2, theta_3, theta_4)*A5(theta_5);
T6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    T5(theta_1, theta_2, theta_3, theta_4, theta_5)*A6(theta_6);

Tn(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    A1(theta_1)*A2(theta_2)*A3(theta_3)*A4(theta_4)*A5(theta_5)*A6(theta_6);

%% Rotation Matrices.
% They describe the rotation from the base to the respective link.

% Helping matrices to extract the rotation matrices R1...R6 from the
% transformation matrices T1...T6.
R_help_before = [1 0 0 0; 0 1 0 0; 0 0 1 0];
R_help_after = [1 0 0; 0 1 0; 0 0 1; 0 0 0];
% Rotation matrices.
R1(theta_1) = R_help_before*T1(theta_1)*R_help_after;
R2(theta_1, theta_2) = R_help_before*T2(theta_1, theta_2)*R_help_after;
R3(theta_1, theta_2, theta_3) = ...
    R_help_before*T3(theta_1, theta_2, theta_3)*R_help_after;
R4(theta_1, theta_2, theta_3, theta_4) = ...
    R_help_before*T4(theta_1, theta_2, theta_3, theta_4)*R_help_after;
R5(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
    R_help_before*T5(theta_1, theta_2, theta_3, theta_4, theta_5)*R_help_after;
R6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    R_help_before*T6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)*R_help_after;


%% Translation Vectors, d1...d6.
% They describe the translation from the base to the respective link.

% Helping matrices to extract the translation vectors d1...d6 from the
% transformation matrices T1...T6.
d_help_before = [1 0 0 0; 0 1 0 0; 0 0 1 0];
d_help_after = [0; 0; 0; 1];
% Translation vectors.
d1(theta_1) = d_help_before*T1(theta_1)*d_help_after;
d2(theta_1, theta_2) = d_help_before*T2(theta_1, theta_2)*d_help_after;
d3(theta_1, theta_2, theta_3) = ...
    d_help_before*T3(theta_1, theta_2, theta_3)*d_help_after;
d4(theta_1, theta_2, theta_3, theta_4) = ...
    d_help_before*T4(theta_1, theta_2, theta_3, theta_4)*d_help_after;
d5(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
    d_help_before*T5(theta_1, theta_2, theta_3, theta_4, theta_5)*d_help_after;
d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    d_help_before*T6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)*d_help_after;

%% Angular part of the Jacobian, J_{angular}.
k = [0 0 1]';
% i=1
z00 = k;
% i=2
z01(theta_1) = R1(theta_1)*k;
% i=3
z02(theta_1, theta_2) = R2*k;
% i=4
z03(theta_1, theta_2, theta_3) = R3(theta_1, theta_2, theta_3)*k;
% i=5
z04(theta_1, theta_2, theta_3, theta_4) = ...
    R4(theta_1, theta_2, theta_3, theta_4)*k;
% i=6
z05(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
    R5(theta_1, theta_2, theta_3, theta_4, theta_5)*k;

J_angular(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
    [z00, ...
    z01(theta_1), ...
    z02(theta_1, theta_2), ...
    z03(theta_1, theta_2, theta_3), ...
    z04(theta_1, theta_2, theta_3, theta_4),...
    z05(theta_1, theta_2, theta_3, theta_4, theta_5)]

%% Linear part of the Jacobian, J_{linear}.
% J_vi = delta d6/delta q_i 
J_v1 = diff(d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_1);
J_v2 = diff(d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_2);
J_v3 = diff(d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_3);
J_v4 = diff(d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_4);
J_v5 = diff(d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_5);
J_v6 = diff(d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_6);

% J_linear(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    
J_linear = [J_v1, J_v2, J_v3, J_v4, J_v5, J_v6]

%% Jacobian J = [J_linear; J_angular].
J = [J_linear; J_angular]