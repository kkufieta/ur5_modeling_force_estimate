

time = joint_variables_ddq_d.Time;

ddq_d = joint_variables_ddq_d.Data;
dq_d = joint_variables_dq_d.Data;
q_d = joint_variables_q_d.Data;

ddq = joint_variables_ddq_modelled.Data;
dq = joint_variables_dq_measured.Data;
q = joint_variables_q_measured.Data;

a_q = zeros(length(time),6);

for i = 1:length(time)
    a_q(i,:) = (ddq_d(i,:)' - ddq(i,:)') + K_1*(dq_d(i,:)' - dq(i,:)') + ...
        K_0*(q_d(i,:)' - q(i,:)');
end

%% Omega = 0.1
omega = 0.1;
K_0 = omega^2*eye(6,6);
K_1 = 2*omega*eye(6,6);

a_q_01 = zeros(length(time),6);
for i = 1:length(time)
    a_q_01(i,:) = (ddq_d(i,:)' - ddq(i,:)') + K_1*(dq_d(i,:)' - dq(i,:)') + ...
        K_0*(q_d(i,:)' - q(i,:)');
end

subplot(4,1,1), plot(time,a_q_01)

%% Omega = 4
omega = 4;
K_0 = omega^2*eye(6,6);
K_1 = 2*omega*eye(6,6);

a_q_4 = zeros(length(time),6);
for i = 1:length(time)
    a_q_4(i,:) = (ddq_d(i,:)' - ddq(i,:)') + K_1*(dq_d(i,:)' - dq(i,:)') + ...
        K_0*(q_d(i,:)' - q(i,:)');
end

subplot(4,1,2), plot(time,a_q_4)

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

K0_11 = [omega_P_1^2, 0, 0; 0, omega_P_2^2, 0; 0, 0, omega_P_3^2];    
K_0 = [K0_11, zeros(3,3); zeros(3,3),omega_P_small^2*eye(3,3)];
K1_11 = [omega_D_1*2, 0, 0; 0, omega_D_2*2, 0; 0, 0, omega_D_3*2];
K_1 = [K1_11, zeros(3,3); zeros(3,3),2*omega_D_small*eye(3,3)];

a_q = zeros(length(time),6);
for i = 1:length(time)
    a_q(i,:) = (ddq_d(i,:)' - ddq(i,:)') + K_1*(dq_d(i,:)' - dq(i,:)') + ...
        K_0*(q_d(i,:)' - q(i,:)');
end

subplot(4,1,3), plot(time,a_q)

%% Error between omega = 0.1 and My Wild Guess
subplot(4,1,4), plot(time, (a_q - a_q_01))