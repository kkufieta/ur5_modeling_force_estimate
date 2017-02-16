% Plot M, G, CDq for identification (of a failed torque estimation)
close all

%% Plot M-matrix part of the torque
% figure, plot(tau_M), 
% legend('M_1', 'M_2', 'M_3', 'M_4', 'M_5', 'M_6')
% 
%% Plot CDq-matrix part of the torque
% figure, plot(tau_CDq)
% legend('CDq_1', 'CDq_2', 'CDq_3', 'CDq_4', 'CDq_5', 'CDq_6')

%% Plot G-matrix part of the torque

figure('Name', 'G_Michael (currently used!)')
subplot(3,2,1), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,1)), legend('G_1'), title('G1_{Michael}')
subplot(3,2,2), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,2)), legend('G_2'), title('G2_{Michael}')
subplot(3,2,3), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,3)), legend('G_3'), title('G3_{Michael}')
subplot(3,2,4), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,4)), legend('G_4'), title('G4_{Michael}')
subplot(3,2,5), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,5)), legend('G_5'), title('G5_{Michael}')
subplot(3,2,6), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,6)), legend('G_6'), title('G6_{Michael}')

figure('Name', 'G_Version1')
subplot(3,2,1), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,1)), legend('G_1'), title('G1_{Version1}')
subplot(3,2,2), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,2)), legend('G_2'), title('G2_{Version1}')
subplot(3,2,3), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,3)), legend('G_3'), title('G3_{Version1}')
subplot(3,2,4), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,4)), legend('G_4'), title('G4_{Version1}')
subplot(3,2,5), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,5)), legend('G_5'), title('G5_{Version1}')
subplot(3,2,6), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,6)), legend('G_6'), title('G6_{Version1}')

figure('Name', 'G_Angel')
subplot(3,2,1), plot(tau_G_angel.Time, tau_G_angel.Data(:,1)), legend('G_1'), title('G1_{Angel}')
subplot(3,2,2), plot(tau_G_angel.Time, tau_G_angel.Data(:,2)), legend('G_2'), title('G2_{Angel}')
subplot(3,2,3), plot(tau_G_angel.Time, tau_G_angel.Data(:,3)), legend('G_3'), title('G3_{Angel}')


% figure, plot(tau_G_angel), legend('1', '2', '3')
% title('tau_G_angel')

