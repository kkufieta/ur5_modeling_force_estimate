%% Compare gravitation vectors

close all

figure('Name', 'tau_G_Michael'),
subplot(3,2,1), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,1))
subplot(3,2,2), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,2))
subplot(3,2,3), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,3))
subplot(3,2,4), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,4))
subplot(3,2,5), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,5))
subplot(3,2,6), plot(tau_G_Michael.Time, tau_G_Michael.Data(:,6))

figure('Name', 'tau_G_Angel'),
subplot(3,2,1), plot(tau_G_angel.Time, tau_G_angel.Data(:,1))
subplot(3,2,2), plot(tau_G_angel.Time, tau_G_angel.Data(:,2))
subplot(3,2,3), plot(tau_G_angel.Time, tau_G_angel.Data(:,3))

figure('Name', 'tau_G_kathi, -g'),
subplot(3,2,1), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,1)*(-1))
subplot(3,2,2), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,2)*(-1))
subplot(3,2,3), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,3)*(-1))
subplot(3,2,4), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,4)*(-1))
subplot(3,2,5), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,5)*(-1))
subplot(3,2,6), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,6)*(-1))

figure('Name', 'tau_G_kathi'),
subplot(3,2,1), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,1))
subplot(3,2,2), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,2))
subplot(3,2,3), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,3))
subplot(3,2,4), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,4))
subplot(3,2,5), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,5))
subplot(3,2,6), plot(tau_G_kathi.Time, tau_G_kathi.Data(:,6))

figure('Name', 'tau_Version_1'),
subplot(3,2,1), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,1))
subplot(3,2,2), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,2))
subplot(3,2,3), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,3))
subplot(3,2,4), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,4))
subplot(3,2,5), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,5))
subplot(3,2,6), plot(tau_G_Version1.Time, tau_G_Version1.Data(:,6))

figure('Name', 'r0_ci_z'),
subplot(3,2,1), plot(r0_c1.Time, r0_c1.Data(:,3))
subplot(3,2,2), plot(r0_c2.Time, r0_c2.Data(:,3))
subplot(3,2,3), plot(r0_c3.Time, r0_c3.Data(:,3))
subplot(3,2,4), plot(r0_c4.Time, r0_c4.Data(:,3))
subplot(3,2,5), plot(r0_c5.Time, r0_c5.Data(:,3))
subplot(3,2,6), plot(r0_c6.Time, r0_c6.Data(:,3))


figure('Name', 'Potential Energy')
plot(P_kathi)