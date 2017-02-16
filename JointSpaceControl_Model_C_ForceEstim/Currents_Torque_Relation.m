% Compare accelerometer measurements vs. modelled
close all

xmin = 0; xmax = 35; ymin = -1000; ymax = 1000;

run('/Users/kasiunia/Documents/Diplomarbeit/DA_Matlab/JointSpaceControl_ForceEstim/FFT_currents.m'), close all
% lower_i_1, lower_i_2, lower_i_3, lower_i_4, lower_i_5, lower_i_6

figure, 
subplot(5,1,1), plot(low_i_1), title('Filtered i_1')
subplot(5,1,2), plot(torque_w_friction.Data(sample_start:sample_end,1)), title('Modelled Torque w friction, t_1')
subplot(5,1,3), plot(torque_mod.Data(sample_start:sample_end,1)), title('Modelled Torque wo friction, t_1')
subplot(5,1,4), plot(estimated_torque_w_friction.Data(sample_start:sample_end,1)), title('Estimated Torque w friction, t_1')
subplot(5,1,5), plot(torque_est.Data(sample_start:sample_end,1)), title('Estimated Torque wo friction, t_1')


%% Filter and Map currents to torques

% figure('Name', 'filtered current vs. torque estimated w friction vs. position')
% subplot(2,3,1), plot3(lower_i_1.Data(:,1), estimated_torque_w_friction.Data(:,1), joint_variables_q_measured.Data(:,1)), xlabel('current_1'), ylabel('torque_1'), zlabel('position_1'), grid on
% subplot(2,3,2), plot3(i_actual_measured.Data(:,2), estimated_torque_w_friction.Data(:,2), joint_variables_q_measured.Data(:,2)), xlabel('current_2'), ylabel('torque_2'), zlabel('position_2'), grid on
% subplot(2,3,3), plot3(i_actual_measured.Data(:,3), estimated_torque_w_friction.Data(:,3), joint_variables_q_measured.Data(:,3)), xlabel('current_3'), ylabel('torque_3'), zlabel('position_3'), grid on
% subplot(2,3,4), plot3(i_actual_measured.Data(:,4), estimated_torque_w_friction.Data(:,4), joint_variables_q_measured.Data(:,4)), xlabel('current_4'), ylabel('torque_4'), zlabel('position_4'), grid on
% subplot(2,3,5), plot3(i_actual_measured.Data(:,5), estimated_torque_w_friction.Data(:,5), joint_variables_q_measured.Data(:,5)), xlabel('current_5'), ylabel('torque_5'), zlabel('position_5'), grid on
% subplot(2,3,6), plot3(i_actual_measured.Data(:,6), estimated_torque_w_friction.Data(:,6), joint_variables_q_measured.Data(:,6)), xlabel('current_6'), ylabel('torque_6'), zlabel('position_6'), grid on
% 
% figure('Name', 'i actual measured vs. torque estimated w friction')
% subplot(2,3,1), plot(i_actual_measured.Data(:,1), estimated_torque_w_friction.Data(:,1)), xlabel('current_1'), ylabel('torque_1')
% subplot(2,3,2), plot(i_actual_measured.Data(:,2), estimated_torque_w_friction.Data(:,2)), xlabel('current_2'), ylabel('torque_2')
% subplot(2,3,3), plot(i_actual_measured.Data(:,3), estimated_torque_w_friction.Data(:,3)), xlabel('current_3'), ylabel('torque_3')
% subplot(2,3,4), plot(i_actual_measured.Data(:,4), estimated_torque_w_friction.Data(:,4)), xlabel('current_4'), ylabel('torque_4')
% subplot(2,3,5), plot(i_actual_measured.Data(:,5), estimated_torque_w_friction.Data(:,5)), xlabel('current_5'), ylabel('torque_5')
% subplot(2,3,6), plot(i_actual_measured.Data(:,6), estimated_torque_w_friction.Data(:,6)), xlabel('current_6'), ylabel('torque_6')
% 
% figure('Name', 'i actual measured vs. position')
% subplot(2,3,1), plot(i_actual_measured.Data(:,1), joint_variables_q_measured.Data(:,1)), xlabel('current_1'), ylabel('position_1')
% subplot(2,3,2), plot(i_actual_measured.Data(:,2), joint_variables_q_measured.Data(:,2)), xlabel('current_2'), ylabel('position_2')
% subplot(2,3,3), plot(i_actual_measured.Data(:,3), joint_variables_q_measured.Data(:,3)), xlabel('current_3'), ylabel('position_3')
% subplot(2,3,4), plot(i_actual_measured.Data(:,4), joint_variables_q_measured.Data(:,4)), xlabel('current_4'), ylabel('position_4')
% subplot(2,3,5), plot(i_actual_measured.Data(:,5), joint_variables_q_measured.Data(:,5)), xlabel('current_5'), ylabel('position_5')
% subplot(2,3,6), plot(i_actual_measured.Data(:,6), joint_variables_q_measured.Data(:,6)), xlabel('current_6'), ylabel('position_6')
% 
% figure('Name', 'torque_estimated_w_fricition vs. position')
% subplot(2,3,1), plot(estimated_torque_w_friction.Data(:,1), joint_variables_q_measured.Data(:,1)), xlabel('torque_1'), ylabel('position_1')
% subplot(2,3,2), plot(estimated_torque_w_friction.Data(:,2), joint_variables_q_measured.Data(:,2)), xlabel('torque_2'), ylabel('position_2')
% subplot(2,3,3), plot(estimated_torque_w_friction.Data(:,3), joint_variables_q_measured.Data(:,3)), xlabel('torque_3'), ylabel('position_3')
% subplot(2,3,4), plot(estimated_torque_w_friction.Data(:,4), joint_variables_q_measured.Data(:,4)), xlabel('torque_4'), ylabel('position_4')
% subplot(2,3,5), plot(estimated_torque_w_friction.Data(:,5), joint_variables_q_measured.Data(:,5)), xlabel('torque_5'), ylabel('position_5')
% subplot(2,3,6), plot(estimated_torque_w_friction.Data(:,6), joint_variables_q_measured.Data(:,6)), xlabel('torque_6'), ylabel('position_6')
% 
% figure('Name', 'torque_modelled vs. position')
% subplot(2,3,1), plot(torque_mod.Data(:,1), joint_variables_q_measured.Data(:,1)), xlabel('torque_1'), ylabel('position_1')
% subplot(2,3,2), plot(torque_mod.Data(:,2), joint_variables_q_measured.Data(:,2)), xlabel('torque_2'), ylabel('position_2')
% subplot(2,3,3), plot(torque_mod.Data(:,3), joint_variables_q_measured.Data(:,3)), xlabel('torque_3'), ylabel('position_3')
% subplot(2,3,4), plot(torque_mod.Data(:,4), joint_variables_q_measured.Data(:,4)), xlabel('torque_4'), ylabel('position_4')
% subplot(2,3,5), plot(torque_mod.Data(:,5), joint_variables_q_measured.Data(:,5)), xlabel('torque_5'), ylabel('position_5')
% subplot(2,3,6), plot(torque_mod.Data(:,6), joint_variables_q_measured.Data(:,6)), xlabel('torque_6'), ylabel('position_6')
% 
% figure('Name', 'i actual measured vs. torque modelled w friction')
% subplot(2,3,1), plot(i_actual_measured.Data(:,1), torque_w_friction.Data(:,1)), xlabel('current_1'), ylabel('torque_1')
% subplot(2,3,2), plot(i_actual_measured.Data(:,2), torque_w_friction.Data(:,2)), xlabel('current_2'), ylabel('torque_2')
% subplot(2,3,3), plot(i_actual_measured.Data(:,3), torque_w_friction.Data(:,3)), xlabel('current_3'), ylabel('torque_3')
% subplot(2,3,4), plot(i_actual_measured.Data(:,4), torque_w_friction.Data(:,4)), xlabel('current_4'), ylabel('torque_4')
% subplot(2,3,5), plot(i_actual_measured.Data(:,5), torque_w_friction.Data(:,5)), xlabel('current_5'), ylabel('torque_5')
% subplot(2,3,6), plot(i_actual_measured.Data(:,6), torque_w_friction.Data(:,6)), xlabel('current_6'), ylabel('torque_6')
% 
% 
% figure('Name', 'torque modelled w friction vs. position')
% subplot(2,3,1), plot(torque_w_friction.Data(:,1), joint_variables_q_measured.Data(:,1)), xlabel('torque_1'), ylabel('position_1')
% subplot(2,3,2), plot(torque_w_friction.Data(:,2), joint_variables_q_measured.Data(:,2)), xlabel('torque_2'), ylabel('position_2')
% subplot(2,3,3), plot(torque_w_friction.Data(:,3), joint_variables_q_measured.Data(:,3)), xlabel('torque_3'), ylabel('position_3')
% subplot(2,3,4), plot(torque_w_friction.Data(:,4), joint_variables_q_measured.Data(:,4)), xlabel('torque_4'), ylabel('position_4')
% subplot(2,3,5), plot(torque_w_friction.Data(:,5), joint_variables_q_measured.Data(:,5)), xlabel('torque_5'), ylabel('position_5')
% subplot(2,3,6), plot(torque_w_friction.Data(:,6), joint_variables_q_measured.Data(:,6)), xlabel('torque_6'), ylabel('position_6')
