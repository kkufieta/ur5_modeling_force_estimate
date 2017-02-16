function print_legend(data_name)
% PRINT_LEGEND_REAL_VS_MODEL returns the legend for the respective data.

data_names_measured = {'joint_variables_q_measured', ...
                       'joint_variables_dq_measured', ...
                       'tcp_speed_measured', ...
                       'torque_target_measured', ...
                       'R_measured', 'k_measured', 'theta_measured',...
                       'i_actual_measured'};    % <-- GESCHUMMELT! 
%                        'tool_acc_measured',...

if strcmp(data_name, 'joint_variables_q_measured')
    legend('q1', 'q2', 'q3', 'q4', 'q5', 'q6')
elseif strcmp(data_name, 'joint_variables_dq_measured')
    legend('dq1', 'dq2', 'dq3', 'dq4', 'dq5', 'dq6')
elseif strcmp(data_name, 'tcp_speed_measured')
    legend('tcp_speed1', 'tcp_speed2', 'tcp_speed3', 'tcp_speed4', 'tcp_speed5', 'tcp_speed6')
elseif strcmp(data_name, 'torque_target_measured')
    legend('m1', 'm2', 'm3', 'm4', 'm5', 'm6')
elseif strcmp(data_name, 'k_measured')
    legend('k1', 'k2', 'k3')
elseif strcmp(data_name, 'theta_measured')
    legend('theta')
elseif strcmp(data_name, 'i_actual_measured')
    legend('i1', 'i2', 'i3', 'i4', 'i5', 'i6')
end