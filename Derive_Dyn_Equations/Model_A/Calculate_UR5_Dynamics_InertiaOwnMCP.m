%% Derive the robotics dynamics:
clear all
tic

%% Get DH parameters, rotation matrices, ...
% Get d1,...,d6, a1,...,a6, alpha1,...,alpha6
% A1(theta_1), ..., A6(theta_6)
% Transformation Matrices T1...T6:
% T1(theta_1), ..., T6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)
% Rotation Matrices R1, ..., R6:
% R1(theta_1), ..., R5(theta_1, theta_2, theta_3, theta_4, theta_5)
% Translation Vectors d1, ..., d6:
% d1(theta_1), ..., d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)
% Angular part of the Jacobian, J_{angular}.
% Linear part of the Jacobian, J_{linear}.
% Jacobian J = [J_linear; J_angular].
run('/Users/kasiunia/Documents/Diplomarbeit/DA_Matlab/Symbolic/Correct_Inertia_own_MCP/Geometrical_Jacobian.m')
syms m l r I Jc_linear Jc_angular R;
syms dq1 dq2 dq3 dq4 dq5 dq6;
syms q1 q2 q3 q4 q5 q6;
%% Kinetic Energy.
% K = 1/2*dq'*D(q)*dq
% D_ci(q) = m_ci*J_vci(q)'*J_vci(q) + J_wci(q)'*R_i(q)'*I_ci*R(q)'*J_wci(q)
% D(q) = sum_from_i_to_n(D_ci(q))

%% Potential Energy.
% P_i = m_i*g'*r_ci


%% Geometrical properties of links of the UR5.
% Masses of the links
m_1 = 3.7000;
m_2 = 8.3930;
m_3 = 2.2750;
m_4 = 1.2190; 
m_5 = 1.2190;
m_6 = 0.1879;

% Lenght of links in [m]
l_1 = 130   *0.001;
l_2 = 542.8 *0.001;
l_3 = 489.3 *0.001;
l_4 = 105   *0.001;
l_5 = 105   *0.001;
l_6 = 35    *0.001;

% Radius of links in [m]
r_1 = 58.9  *0.001;
r_2 = 43    *0.001;
r_3 = 37.6  *0.001;
r_4 = 38.4  *0.001;
r_5 = 38.4  *0.001;
r_6 = 38.4  *0.001;

% Center of mass vectors in [m], in body frame
r1_c1 = [0,         0,   0]     *0.001;
r2_c2 = [212.5,     0,   135]   *0.001;
r3_c3 = [206.25,    0,   17.5]  *0.001;
r4_c4 = [0,         0,  -2.5]   *0.001;
r5_c5 = [0,         0,  -2.5]   *0.001;
r6_c6 = [0,         0,  -17.5]  *0.001;

%% Center of mass vectors (in [m]), in inertial frame.
% Calculate by using the translation vectors:
% r0_ci = di + R_i*ri_ci
% d1(theta_1) 
% d2(theta_1, theta_2) 
% d3(theta_1, theta_2, theta_3) 
% d4(theta_1, theta_2, theta_3, theta_4)
% d5(theta_1, theta_2, theta_3, theta_4, theta_5)
% d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)
% 
% R1(theta_1)
% R2(theta_1, theta_2)
% R3(theta_1, theta_2, theta_3) 
% R4(theta_1, theta_2, theta_3, theta_4)
% R5(theta_1, theta_2, theta_3, theta_4, theta_5) 
% R6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)

r0_c1(theta_1) = d1(theta_1) + R1(theta_1)*r1_c1';
r0_c2(theta_1, theta_2) = ...
    d2(theta_1, theta_2) + R2(theta_1, theta_2)*r2_c2';
r0_c3(theta_1, theta_2, theta_3)  = ...
    d3(theta_1, theta_2, theta_3) + R3(theta_1, theta_2, theta_3)*r3_c3';
r0_c4(theta_1, theta_2, theta_3, theta_4) = ...
    d4(theta_1, theta_2, theta_3, theta_4) + R4(theta_1, theta_2, theta_3, theta_4)*r4_c4';
r0_c5(theta_1, theta_2, theta_3, theta_4, theta_5)  = ...
    d5(theta_1, theta_2, theta_3, theta_4, theta_5) + R5(theta_1, theta_2, theta_3, theta_4, theta_5)*r5_c5';
r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    d6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) + ...
            R6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)*r6_c6';

%% Calculate Potential Energy P
% P_i = m_i*g'*r_ci
% where
% g:    vector giving the direction of gravity in the inertial frame
% r_ci: coordinates of the center of mass of link i in the inertial frame
g = [0 0 -9.81];

P_1(theta_1) = ...
    m_1*g*r0_c1(theta_1);
P_2(theta_1, theta_2) = ...
    m_2*g*r0_c2(theta_1, theta_2);
P_3(theta_1, theta_2, theta_3) = ...
    m_3*g*r0_c3(theta_1, theta_2, theta_3);
P_4(theta_1, theta_2, theta_3, theta_4) = ...
    m_4*g*r0_c4(theta_1, theta_2, theta_3, theta_4);
P_5(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
    m_5*g*r0_c5(theta_1, theta_2, theta_3, theta_4, theta_5);
P_6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    m_6*g*r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6);

P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    P_1(theta_1) + ...
    P_2(theta_1, theta_2) + ...
    P_3(theta_1, theta_2, theta_3) + ...
    P_4(theta_1, theta_2, theta_3, theta_4) + ...
    P_5(theta_1, theta_2, theta_3, theta_4, theta_5) + ...
    P_6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6);

P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    simplify(P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6));
P = vpa(P, 10);

%% Gravity vector
g_1 = diff(P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_1);
g_2 = diff(P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_2);
g_3 = diff(P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_3);
g_4 = diff(P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_4);
g_5 = diff(P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_5);
g_6 = diff(P(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_6);

g = [g_1; g_2; g_3; g_4; g_5; g_6];
g = vpa(g,10);
g = simplify(g);
g = vpa(g,10);

filename = 'G_Vector.m';
fid = fopen(filename, 'w');
for k = 1:6
	g_k = char(g(k));
	fprintf(fid, 'g%d = %s;\n',k,g_k);
end
fclose(fid);

%% Linear part of the Jacobian Jc1, Jc1_linear.

Jc1_v1 = diff(r0_c1(theta_1),theta_1);
Jc1_v2 = zeros(3,1);
Jc1_v3 = zeros(3,1);
Jc1_v4 = zeros(3,1);
Jc1_v5 = zeros(3,1);
Jc1_v6 = zeros(3,1);

Jc1_linear = [Jc1_v1, Jc1_v2, Jc1_v3, Jc1_v4, Jc1_v5, Jc1_v6]

%% Linear part of the Jacobian Jc2, Jc2_linear.

Jc2_v1 = diff(r0_c2(theta_1, theta_2),theta_1);
Jc2_v2 = diff(r0_c2(theta_1, theta_2),theta_2);
Jc2_v3 = zeros(3,1);
Jc2_v4 = zeros(3,1);
Jc2_v5 = zeros(3,1);
Jc2_v6 = zeros(3,1);

Jc2_linear = [Jc2_v1, Jc2_v2, Jc2_v3, Jc2_v4, Jc2_v5, Jc2_v6]

%% Linear part of the Jacobian Jc3, Jc3_linear.

Jc3_v1 = diff(r0_c3(theta_1, theta_2, theta_3),theta_1);
Jc3_v2 = diff(r0_c3(theta_1, theta_2, theta_3),theta_2);
Jc3_v3 = diff(r0_c3(theta_1, theta_2, theta_3),theta_3);
Jc3_v4 = zeros(3,1);
Jc3_v5 = zeros(3,1);
Jc3_v6 = zeros(3,1);

Jc3_linear = [Jc3_v1, Jc3_v2, Jc3_v3, Jc3_v4, Jc3_v5, Jc3_v6]

%% Linear part of the Jacobian Jc4, Jc4_linear.

Jc4_v1 = diff(r0_c4(theta_1, theta_2, theta_3, theta_4),theta_1);
Jc4_v2 = diff(r0_c4(theta_1, theta_2, theta_3, theta_4),theta_2);
Jc4_v3 = diff(r0_c4(theta_1, theta_2, theta_3, theta_4),theta_3);
Jc4_v4 = diff(r0_c4(theta_1, theta_2, theta_3, theta_4),theta_4);
Jc4_v5 = zeros(3,1);
Jc4_v6 = zeros(3,1);
    
Jc4_linear = [Jc4_v1, Jc4_v2, Jc4_v3, Jc4_v4, Jc4_v5, Jc4_v6]

%% Linear part of the Jacobian Jc5, Jc5_linear.

Jc5_v1 = diff(r0_c5(theta_1, theta_2, theta_3, theta_4, theta_5),theta_1);
Jc5_v2 = diff(r0_c5(theta_1, theta_2, theta_3, theta_4, theta_5),theta_2);
Jc5_v3 = diff(r0_c5(theta_1, theta_2, theta_3, theta_4, theta_5),theta_3);
Jc5_v4 = diff(r0_c5(theta_1, theta_2, theta_3, theta_4, theta_5),theta_4);
Jc5_v5 = diff(r0_c5(theta_1, theta_2, theta_3, theta_4, theta_5),theta_5);
Jc5_v6 = zeros(3,1);
    
Jc5_linear = [Jc5_v1, Jc5_v2, Jc5_v3, Jc5_v4, Jc5_v5, Jc5_v6]

%% Linear part of the Jacobian Jc6, Jc6_linear.

Jc6_v1 = diff(r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_1);
Jc6_v2 = diff(r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_2);
Jc6_v3 = diff(r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_3);
Jc6_v4 = diff(r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_4);
Jc6_v5 = diff(r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_5);
Jc6_v6 = diff(r0_c6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6),theta_6);
    
Jc6_linear = [Jc6_v1, Jc6_v2, Jc6_v3, Jc6_v4, Jc6_v5, Jc6_v6]

        
%% Rotation axes for angular part of the Jacobians Jci_angular.
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

%% Angular part of the Jacobian Jc1, Jc1_angular.
Jc1_angular = [z00, zeros(3,1), zeros(3,1), zeros(3,1), zeros(3,1), zeros(3,1)]
Jc2_angular(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
        [z00, z01(theta_1), ...
        zeros(3,1), zeros(3,1), zeros(3,1), zeros(3,1)]
Jc3_angular(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
        [z00, z01(theta_1), z02(theta_1, theta_2), ...
        zeros(3,1), zeros(3,1), zeros(3,1)]
Jc4_angular(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
        [z00, ...
        z01(theta_1), ...
        z02(theta_1, theta_2), ...
        z03(theta_1, theta_2, theta_3), ...
        zeros(3,1), zeros(3,1)]
Jc5_angular(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
        [z00, ...
        z01(theta_1), ...
        z02(theta_1, theta_2), ...
        z03(theta_1, theta_2, theta_3), ...
        z04(theta_1, theta_2, theta_3, theta_4),...
        zeros(3,1)]
Jc6_angular(theta_1, theta_2, theta_3, theta_4, theta_5) = ...
        [z00, ...
        z01(theta_1), ...
        z02(theta_1, theta_2), ...
        z03(theta_1, theta_2, theta_3), ...
        z04(theta_1, theta_2, theta_3, theta_4),...
        z05(theta_1, theta_2, theta_3, theta_4, theta_5)]
    
    
%% Simplify Jacobians
Jc1_linear = simplify(Jc1_linear);
Jc2_linear = simplify(Jc2_linear);
Jc3_linear = simplify(Jc3_linear);
Jc4_linear = simplify(Jc4_linear);
Jc5_linear = simplify(Jc5_linear);
Jc6_linear = simplify(Jc6_linear);

Jc2_angular = simplify(Jc2_angular);
Jc3_angular = simplify(Jc3_angular);
Jc4_angular = simplify(Jc4_angular);
Jc5_angular = simplify(Jc5_angular);
Jc6_angular = simplify(Jc6_angular);


    
%% Inertia Tensors I_c1, ... I_c6.
% Assumption: All links are homogeneous circular cylinders with the center
% of mass lying on the geometric center of the cylinder
% If z is rotation axis, then:
% I_zz = 1/2*m*r^2
% I_yy = I_xx = 1/12*m*(3*r^2+l^2)

I_middle(m, l, r) = 1/2*m*r^2;
I_sides(m, l, r) = 1/12*m*(3*r^2+l^2);

I_x(m, l, r) = [I_middle(m, l, r),   0,                     0; 
                0,                  I_sides(m, l, r),       0;
                0,                  0,                      I_sides(m, l, r)];
            
I_y(m, l, r) = [I_sides(m, l, r),   0,                      0; 
                0,                  I_middle(m, l, r),      0;
                0,                  0,                      I_sides(m, l, r)];
            
I_z(m, l, r) = [I_sides(m, l, r),   0,                      0; 
                0,                  I_sides(m, l, r),       0;
                0,                  0,                      I_middle(m, l, r)];



% Inertia Tensors I_c1, ..., I_c6
% I_c1 (around y), I_c2 (around x), I_c3 (around x), I_c4 (around y)
% I_c5 (around y), I_c6 (around z)
I_c1 = I_y(m_1, l_1, r_1);
I_c2 = I_x(m_2, l_2, r_2);
I_c3 = I_x(m_3, l_3, r_3);
I_c4 = I_z(m_4, l_4, r_4);
I_c5 = I_z(m_5, l_5, r_5);
I_c6 = I_z(m_6, l_6, r_6);

%% Convert all matrices from symbolic to numeric.
I_c1 = double(I_c1);
I_c2 = double(I_c2);
I_c3 = double(I_c3);
I_c4 = double(I_c4);
I_c5 = double(I_c5);
I_c6 = double(I_c6);

%% Calculate D(q)
% D_1 = m1*Jc1_linear'*Jc1_linear + Jc1_angular'*R1*I1*R1'*Jc1_angular;
D_1(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    m_1*transpose(Jc1_linear)*Jc1_linear + ...
    transpose(Jc1_angular)*R1(theta_1)*I_c1*transpose(R1(theta_1))*Jc1_angular;

D_2(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    m_2*transpose(Jc2_linear)*Jc2_linear + ...
    transpose(Jc2_angular)*R2(theta_1, theta_2)*I_c2*transpose(R2(theta_1, theta_2))*Jc2_angular;

D_3(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    m_3*transpose(Jc3_linear)*Jc3_linear + ...
    transpose(Jc3_angular)*R3(theta_1, theta_2, theta_3) *...
    I_c3*transpose(R3(theta_1, theta_2, theta_3) )*Jc3_angular;

D_4(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    m_4*transpose(Jc4_linear)*Jc4_linear + ...
    transpose(Jc4_angular)*R4(theta_1, theta_2, theta_3, theta_4)*...
    I_c4*transpose(R4(theta_1, theta_2, theta_3, theta_4))*Jc4_angular;

D_5(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    m_5*transpose(Jc5_linear)*Jc5_linear + ...
    transpose(Jc5_angular)*R5(theta_1, theta_2, theta_3, theta_4, theta_5)*I_c5...
    *transpose(R5(theta_1, theta_2, theta_3, theta_4, theta_5))*Jc5_angular;

D_6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
    m_6*transpose(Jc6_linear)*Jc6_linear + ...
    transpose(Jc6_angular)*R6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)*I_c6...
    *transpose(R6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6))*Jc6_angular;

D_1 = simplify(D_1);
D_1 = vpa(D_1,10);
D_2 = simplify(D_2);
D_2 = vpa(D_2,10);
D_3 = simplify(D_3);
D_3 = vpa(D_3,10);
D_4 = simplify(D_4);
D_4 = vpa(D_4,10);
D_5 = simplify(D_5);
D_5 = vpa(D_5,10);
D_6 = simplify(D_6);
D_6 = vpa(D_6,10);



% D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) = ...
%     D_1(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) + ...
%     D_2(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) + ...
%     D_3(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) + ...
%     D_4(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) + ...
%     D_5(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6) + ...
%     D_6(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6);

D(q1, q2, q3, q4, q5, q6) = ...
    D_1(q1, q2, q3, q4, q5, q6) + ...
    D_2(q1, q2, q3, q4, q5, q6) + ...
    D_3(q1, q2, q3, q4, q5, q6) + ...
    D_4(q1, q2, q3, q4, q5, q6) + ...
    D_5(q1, q2, q3, q4, q5, q6) + ...
    D_6(q1, q2, q3, q4, q5, q6);

D = simplify(D);
D = vpa(D, 10);

filename = 'D_Matrix.m';
fid = fopen(filename, 'w');
fprintf(fid, char(D))


%% Christoffel symbols
% c_ijk = 1/2*(diff(d_kj, q_i) + diff(d_ki, q_j) - diff(d_ij, q_k))

% Make function handle out of D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6)
% h_D = matlabFunction(D);
% diff_D_q_1 = diff(h_D, theta_1);    % size: (36, 1)
% diff_D_q_2 = diff(h_D, theta_2);    % size: (36, 1)
% diff_D_q_3 = diff(h_D, theta_3);    % size: (36, 1)
% diff_D_q_4 = diff(h_D, theta_4);    % size: (36, 1)
% diff_D_q_5 = diff(h_D, theta_5);    % size: (36, 1)
% diff_D_q_6 = diff(h_D, theta_6);    % size: (36, 1)

diff_D_theta_1 = diff(D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6), theta_1);    % size: (36, 1)
diff_D_theta_2 = diff(D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6), theta_2);    % size: (36, 1)
diff_D_theta_3 = diff(D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6), theta_3);    % size: (36, 1)
diff_D_theta_4 = diff(D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6), theta_4);    % size: (36, 1)
diff_D_theta_5 = diff(D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6), theta_5);    % size: (36, 1)
diff_D_theta_6 = diff(D(theta_1, theta_2, theta_3, theta_4, theta_5, theta_6), theta_6);    % size: (36, 1)
h_diff_D_q_1 = matlabFunction(diff_D_theta_1);
h_diff_D_q_2 = matlabFunction(diff_D_theta_2);
h_diff_D_q_3 = matlabFunction(diff_D_theta_3);
h_diff_D_q_4 = matlabFunction(diff_D_theta_4);
h_diff_D_q_5 = matlabFunction(diff_D_theta_5);
h_diff_D_q_6 = matlabFunction(diff_D_theta_6);

diff_D_q_1 = h_diff_D_q_1();
diff_D_q_2 = h_diff_D_q_2(theta_2, theta_3, theta_4, theta_5);
diff_D_q_3 = h_diff_D_q_3(theta_2, theta_3, theta_4, theta_5);
diff_D_q_4 = h_diff_D_q_4(theta_2, theta_3, theta_4, theta_5);
diff_D_q_5 = h_diff_D_q_5(theta_2, theta_3, theta_4, theta_5);
diff_D_q_6 = h_diff_D_q_6();

diff_D_q_1 = vpa(diff_D_q_1, 10);
diff_D_q_1 = simplify(diff_D_q_1);
diff_D_q_2 = vpa(diff_D_q_2, 10);
diff_D_q_2 = simplify(diff_D_q_2);
diff_D_q_3 = vpa(diff_D_q_3, 10);
diff_D_q_3 = simplify(diff_D_q_3);
diff_D_q_4 = vpa(diff_D_q_4, 10);
diff_D_q_4 = simplify(diff_D_q_4);
diff_D_q_5 = vpa(diff_D_q_5, 10);
diff_D_q_5 = simplify(diff_D_q_5);
diff_D_q_6 = vpa(diff_D_q_6, 10);
diff_D_q_6 = simplify(diff_D_q_6);


diff_D_q = {diff_D_q_1, diff_D_q_2, diff_D_q_3, ...
    diff_D_q_4, diff_D_q_5,diff_D_q_6};


% c_ijk = 1/2*(diff(D_kj, q_i) + diff(D_ki, q_j) - diff(D_ij, q_k))
% diff(D_kj, q_i) = diff_D_q(i, k, j)
% diff(D_ki, q_j) = diff_D_q(j, k, i)
% diff(D_ij, q_k) = diff_D_q(k, i, j)
c = {};
for i = 1:6
    for j = 1:6
        for k = 1:6
            c{i,j,k} = 1/2*(diff_D_q{i}(k, j) + diff_D_q{j}(k, i) - diff_D_q{k}(i, j));
        end
        c{i,j,k} = simplify(c{i,j,k});
    end
end

C = {};
dq = {dq1 dq2 dq3 dq4 dq5 dq6}
for k = 1:6
    for j = 1:6
        C{k,j} = 0;
        for i = 1:6
            C{k,j} =  C{k,j} + c{i,j,k}*dq{i};
        end
        C{k,j} = vpa(C{k,j}, 10);
        C{k,j} = simplify(C{k,j});
    end
end


%% Print Matrices to *.m-files

filename = 'C_Matrix.m';
fid = fopen(filename, 'w');
% k = 3;
% j = 3;
% c_kj = char(C{k,j});
% fprintf(fid, 'c_%d%d = %s',k,j,c_kj)
for k = 1:6
    for j = 1:6
        c_kj = char(C{k,j});
        fprintf(fid, 'c%d%d = %s;\n',k,j,c_kj);
    end
end
fclose(fid);


Calc_Dynamics_Time = toc
