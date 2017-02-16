% close all;

%% PLOT_RECORDED_DATA, load and plot the measurement data from the UR5.

% mat_folder_name = 'RecordedUR5Data/Movement_No1/mat_files/';
% mat_folder_name = 'RecordedUR5Data/Movement_No2/mat_files/';
mat_folder_name = 'RecordedUR5Data/Movement_No3_Acc/mat_files/';

data_names_measured = {'joint_variables_q_measured', ...
                       'joint_variables_dq_measured', ...
                       'tcp_speed_measured', ...
                       'torque_target_measured', ...
                       'R_measured', 'k_measured', 'theta_measured',...
                       'i_actual_measured'};    % <-- GESCHUMMELT! 
%                        'tool_acc_measured',...

% Not modelled yet: tcp_force_modelled, tool_acc_modelled, i_modelled,
%                   m_modelled
data_names_modelled = {'joint_variables_q_modelled', ...
                       'joint_variables_dq_modelled', ...
                       'tcp_speed_modelled', ...
                       'torque_mod', ...
                       'R_modelled', 'k_modelled', 'theta_modelled', ...
                       'i_target_measured'};    % <-- GESCHUMMELT!
%                        'tool_acc_modelled',...

%% Load and plot the data.
if size(data_names_modelled) == size(data_names_measured)       
    for i=1:length(data_names_measured)
    %     load([mat_folder_name, data_names_measured{i}])

            figure
                subplot(3,1,1), 
                    eval(['plot(', data_names_measured{i}, ')'])
                    title(data_names_measured{i})
%                     if strcmp(data_names_measured{i}, 'torque_target_measured')
%                         legend('m1', 'm2', 'm3', 'm4', 'm5', 'm6')
%                     end
                    print_legend(data_names_measured{i})
                subplot(3,1,2), 
                    eval(['plot(', data_names_modelled{i}, ')'])
                    title(data_names_modelled{i})
%                     if strcmp(data_names_measured{i}, 'torque_target_measured')
%                         legend('m1', 'm2', 'm3', 'm4', 'm5', 'm6')
%                     end
                    print_legend(data_names_measured{i})
                subplot(3,1,3),
                    eval(['plot(', data_names_measured{i}, '-', ...
                        data_names_modelled{i}, ')'])
                    title('Difference error: measured - modelled')
    end
else
    error('Size of "data_names_measured" and "data_names_modelled must be the same.')
end

clear('data_names', 'mat_folder_name','i')

%% 

% floor(q_target.time(end))
% 
% figure
%   subplot(2,1,1)
%     plot(joint_variables_q_d), hold on
%     plot(joint_variables_q_mod,'-.')
%     plot(joint_variables_q_measured,'--')
%     legend('q(1)', 'q(2)', 'q(3)', 'q(4)', 'q(5)', 'q(6)')
%     title('Joint variables: q, q_d')
%     ylabel('q_mod (-.), q_d (-), q_measured (--)')
%   subplot(2,1,2)
%     plot(joint_variables_q_d-joint_variables_q_mod)
%     title('Joint variables, error: (q_d - q)')
%     ylabel('q_d - q')
%     
% figure
% title('Joint variables: dq, dq_d')
%   subplot(2,1,1)
%     plot(joint_variables_dq_d), hold on
%     plot(joint_variables_dq_mod,'-.')
%     plot(joint_variables_dq_measured,'--')
%     legend('dq(1)', 'dq(2)', 'dq(3)', 'dq(4)', 'dq(5)', 'dq(6)')
%     title('Joint variables: dq, dq_d')
%     ylabel('dq_mod (-.), dq_d (-), dq_measured (--)')
%   subplot(2,1,2)
%     plot(joint_variables_dq_d-joint_variables_dq_mod)
%     title('Joint variables, error: (dq_d - dq)')
%     ylabel('dq_d - dq')
%     
% figure
% title('TCP vector, measured vs modelled')
% subplot(5,1,1)
%   plot(XYZ_measured), hold on
%   plot(XYZ_mod,'k')
%   title('XYZ / d')
% subplot(5,1,2)
%   plot(k_measured.Data(:,1)), hold on
%   plot(k.Data(:,1),'k--')  
%   legend('kx_m','kx')
%   title('kx_m and kx')
% subplot(5,1,3)
%   plot(k_measured.Data(:,2)), hold on
%   plot(k.Data(:,2),'k--')  
%   legend('ky_m','ky')
%   title('ky_m and ky')
% subplot(5,1,4)
%   plot(k_measured.Data(:,3)), hold on
%   plot(k.Data(:,3),'k--')  
%   legend('kz_m','kz')
%   title('kz_m and kz')
% subplot(5,1,5)
%   plot(theta_measured.Data), hold on
%   plot(theta.Data,'k--')  
%   legend('theta_m', 'theta')
%   title('theta_m and theta')
% 
% figure
%   subplot(2,1,1)
%     plot(theta_measured), hold on
%     plot(theta,'k--')  
%     legend('theta_m', 'theta')
%     title('theta_m and theta')
%   subplot(2,1,2)
%     plot(theta_measured - theta), hold on 
%     legend('theta_m - theta')
%     title('theta_m - theta')
%   
% % subplot(4,1,2)
% %   plot(RxRyRz_measured.Data(:,1)), hold on
% %   plot(RxRyRz.Data(:,1),'k--')  
% %   legend('Rx_m','Rx')
% %   title('Rx_m and Rx')
% % subplot(4,1,3)
% %   plot(RxRyRz_measured.Data(:,2)), hold on
% %   plot(RxRyRz.Data(:,2),'k--')  
% %   legend('Ry_m','Ry')
% %   title('Ry_m and Ry')
% % subplot(4,1,4)
% %   plot(RxRyRz_measured.Data(:,3)), hold on
% %   plot(RxRyRz.Data(:,3),'k--')  
% %   legend('Rz_m','Rz')
% %   title('Rz_m and Rz')