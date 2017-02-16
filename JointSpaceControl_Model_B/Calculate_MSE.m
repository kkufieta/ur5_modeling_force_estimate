%% Calculate the Mean Square Error (MSE) of positions, velocities and torques
% MSE = 1/n sum_N(estimated-measured)^2

% mat_folder_name = 'RecordedUR5Data/Movement_No3_Acc/mat_files/';
% 
% data_names_measured = {'joint_variables_q_measured', ...
%                        'joint_variables_dq_measured', ...
%                        'tcp_speed_measured', ...
%                        'torque_target_measured', ...
%                        'R_measured', 'k_measured', 'theta_measured',...
%                        'i_actual_measured'};    % <-- GESCHUMMELT! 
% %                        'tool_acc_measured',...
% 
% % Not modelled yet: tcp_force_modelled, tool_acc_modelled, i_modelled,
% %                   m_modelled
% data_names_modelled = {'joint_variables_q_modelled', ...
%                        'joint_variables_dq_modelled', ...
%                        'tcp_speed_modelled', ...
%                        'torque_mod', ...
%                        'R_modelled', 'k_modelled', 'theta_modelled', ...
%                        'i_target_measured'};    % <-- GESCHUMMELT!
% %                        'tool_acc_modelled',...

q_errors = joint_variables_q_measured.Data - joint_variables_q_modelled.Data;
dq_errors = joint_variables_dq_measured.Data - joint_variables_dq_modelled.Data;
torque_errors = torque_target_measured.Data - torque_mod.Data;

q_MSE = mean(q_errors.^2)
dq_MSE = mean(dq_errors.^2)
torque_MSE = mean(torque_errors.^2)
% 
% min_torque = min(torque_target_measured.Data)
% max_torque = max(torque_target_measured.Data)
% 
% min_pos = min(joint_variables_q_measured.Data)
% max_pos = max(joint_variables_q_measured.Data)
% 
% min_vel = min(joint_variables_dq_measured.Data)
% max_vel = max(joint_variables_dq_measured.Data)

torque_mean_measured = mean(torque_target_measured.Data)
torque_mean_modelled = mean(torque_mod.Data)