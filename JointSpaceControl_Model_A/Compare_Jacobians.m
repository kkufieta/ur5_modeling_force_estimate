% Compare Jacobians
close all

%% J_Kathi & J_Corke
figure
plot(J_kathi-J_Corke), title('J_kathi - J_Corke')

legend('J_11', 'J_12', 'J_13', 'J_14', 'J_15', 'J_16', ...
       'J_21', 'J_22', 'J_23', 'J_24', 'J_25', 'J_26', ...
       'J_31', 'J_32', 'J_33', 'J_34', 'J_35', 'J_36', ...
       'J_41', 'J_42', 'J_43', 'J_44', 'J_45', 'J_46', ...
       'J_51', 'J_52', 'J_53', 'J_54', 'J_55', 'J_56', ...
       'J_61', 'J_62', 'J_63', 'J_64', 'J_65', 'J_66')

%% J_Kathi & Jn_Corke
% --> This is not comparable, must be indeed not the same
% figure, plot(J_kathi - J_n_Corke), title('J_kathi - Jn_Corke')

%% Ja_Kathi & Ja_Corke
figure, plot(J_a_kathi - J_a_Corke), title('Ja_kathi - Ja_Corke')

%% Ja_Kathi & J_Kathi
figure, plot(J_a_kathi - J_kathi), title('Ja_kathi - J_kathi')

%% Ja_Corke & J_Corke
figure, plot(J_a_Corke - J_Corke), title('Ja_Corke - J_Corke')

%% J_Kathi - J_Corke & Ja_Kathi - Ja_Corke
figure, plot(J_a_kathi - J_a_Corke-J_kathi + J_Corke), 
title('J_a_kathi - J_a_Corke-J_kathi + J_Corke')


%% d/dt J_Corke * dq & dJ*dq_Corke
figure, plot(d_dt_J_dq_Corke - dJ_dq_Corke), title('d_dt_J_dq_Corke - dJ_dq_Corke')

%% d/dt Jn_Corke * dq & dJ*dq_Corke
figure, plot(d_dt_Jn_dq_Corke - dJ_dq_Corke), title('d_dt_Jn_dq_Corke - dJ_dq_Corke')

%% d/dt Ja_Corke * dq & dJ*dq_Corke
figure, plot(d_dt_Ja_dq_Corke - dJ_dq_Corke), title('d_dt_Ja_dq_Corke - dJ_dq_Corke')

       