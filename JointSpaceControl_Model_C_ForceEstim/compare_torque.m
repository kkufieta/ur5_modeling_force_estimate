%% COMPARE TORQUE: torque_modelled, torque_measured, torque_estimated
close all

figure, plot(torque_mod), title('Modelled Torque')
figure, plot(torque_est), title('Estimated Torque')
figure, plot(torque_target_measured), title('Measured Torque')
                 
%% Compare Torques without modifying the data
figure, 
subplot(3,2,1), plot(torque_mod.Time, torque_mod.Data(:,1), ...
                     torque_target_measured.Time, torque_target_measured.Data(:,1)),
                legend('torque_{mod}', 'torque_{meas}')
                title('Torque 1')
                xlim([0 30])
%                 ylim([-4 7])
%                 axis([0 30 -1 1])
subplot(3,2,2), plot(torque_mod.Time, torque_mod.Data(:,2), ...
                     torque_target_measured.Time, torque_target_measured.Data(:,2)),
                 legend('torque_{mod}','torque_{meas}')
                 title('Torque 2')
                 xlim([0 30])
%                  ylim([-5 40])
subplot(3,2,3), plot(torque_mod.Time, torque_mod.Data(:,3), ...
                     torque_target_measured.Time, torque_target_measured.Data(:,3)),
                 legend('torque_{mod}','torque_{meas}')
                 title('Torque 3')
                 xlim([0 30])
%                  ylim([-6 6])
subplot(3,2,4), plot(torque_mod.Time, torque_mod.Data(:,4), ...
                     torque_target_measured.Time, torque_target_measured.Data(:,4)),
                 legend('torque_{mod}', 'torque_{meas}')
                 title('Torque 4')
                 xlim([0 30])
%                  ylim([-0.2 0.45])
subplot(3,2,5), plot(torque_mod.Time, torque_mod.Data(:,5), ...
                     torque_target_measured.Time, torque_target_measured.Data(:,5)),
                 legend('torque_{mod}', 'torque_{meas}')
                 title('Torque 5')
                 xlim([0 30])
%                  ylim([-0.08 0.15])
subplot(3,2,6), plot(torque_mod.Time, torque_mod.Data(:,6), ...
                     torque_target_measured.Time, torque_target_measured.Data(:,6)),
                 legend('torque_{mod}', 'torque_{meas}')
                 title('Torque 6')
                 xlim([0 30])
%                  ylim([-0.01 0.01])

                 
%% Compare Torques without modifying the data
figure, 
plot(torque_mod.Time, torque_mod.Data(:,1), ...
     torque_est.Time, torque_est.Data(:,1), ...
     torque_target_measured.Time, torque_target_measured.Data(:,1)),
legend('torque_{mod}', 'torque_{est}', 'torque_{meas}')
title('Torque 1')
xlim([0 30])
%                 ylim([-4 7])
%                 axis([0 30 -1 1])
figure, 
plot(torque_mod.Time, torque_mod.Data(:,2), ...
     torque_est.Time, torque_est.Data(:,2), ...
     torque_target_measured.Time, torque_target_measured.Data(:,2)),
legend('torque_{mod}', 'torque_{est}', 'torque_{meas}')
title('Torque 2')
xlim([0 30])
%                  ylim([-5 40])
figure, 
plot(torque_mod.Time, torque_mod.Data(:,3), ...
     torque_est.Time, torque_est.Data(:,3),...
     torque_target_measured.Time, torque_target_measured.Data(:,3)),
legend('torque_{mod}', 'torque_{est}', 'torque_{meas}')
title('Torque 3')
xlim([0 30])
%                  ylim([-6 6])
figure, 
plot(torque_mod.Time, torque_mod.Data(:,4), ...
     torque_est.Time, torque_est.Data(:,4), ...
     torque_target_measured.Time, torque_target_measured.Data(:,4)),
legend('torque_{mod}', 'torque_{est}', 'torque_{meas}')
title('Torque 4')
xlim([0 30])
%                  ylim([-0.2 0.45])
figure, 
plot(torque_mod.Time, torque_mod.Data(:,5), ...
     torque_est.Time, torque_est.Data(:,6), ...
     torque_target_measured.Time, torque_target_measured.Data(:,5)),
legend('torque_{mod}', 'torque_{est}', 'torque_{meas}')
title('Torque 5')
xlim([0 30])
%                  ylim([-0.08 0.15])
figure, 
plot(torque_mod.Time, torque_mod.Data(:,6), ...
     torque_est.Time, torque_est.Data(:,6), ...
     torque_target_measured.Time, torque_target_measured.Data(:,6)),
legend('torque_{mod}', 'torque_{est}', 'torque_{meas}')
title('Torque 6')
xlim([0 30])
%                  ylim([-0.01 0.01])