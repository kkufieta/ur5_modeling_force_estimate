
% -------------------------------------------------------------------------
% close all existing figures and clear workspace (might not be needed)
% -------------------------------------------------------------------------
%     clear all;
    close all;
    clc;
    disp('testplot.m')
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
% Load and/or generate any data needed for the plot objects
% -------------------------------------------------------------------------
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


% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
% Define my colors
% -------------------------------------------------------------------------
    % Favorites
    light_cherry_pink =  [255, 158, 158]/255;
    light_purple =  [184, 184, 255]/255;
    
    grey        = [85, 98, 112]/255;
    pacifica    = [78, 205, 196]/255;
    apple_yellow= [199, 244, 100]/255;
    cherry_pink = [255, 107, 107]/255;
    blue        = [122, 149, 255]/255;
    turkis      = [162, 242, 209]/255;
    purple      = [140, 117, 209]/255;
    % Additional
    pink        = [255, 140, 196]/255;
    reddish     = [196, 77, 88]/255;

    dark_grey        = [53, 60, 70]/255;
    dark_pacifica    = [45, 159, 152]/255;
    dark_apple_yellow= [124, 176, 12]/255;
    dark_cherry_pink = [235, 0, 0]/255;
    dark_blue        = [0, 50, 250]/255;
    dark_turkis      = [32, 217, 140]/255;
    dark_purple      = [90, 50, 149]/255;
    % Additional
    dark_pink        = [214, 0, 104]/255;
    dark_reddish     = [187, 62, 75]/255;
    
    ddark_grey        = [31, 35, 40]/255;
    ddark_pacifica    = [28, 99, 95]/255;
    ddark_apple_yellow= [91, 129, 9]/255;
    ddark_cherry_pink = [184, 0, 0]/255;
    ddark_blue        = [0, 35, 173]/255;
    ddark_turkis      = [23, 151, 97]/255;
    ddark_purple      = [65, 43, 130]/255;
    % Additional
    ddark_pink        = [163, 0, 79]/255;
    ddark_reddish     = [130, 43, 52]/255;
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
% Choose desired output format
% -------------------------------------------------------------------------
    % Fit axes and figure sizes to desired output format
%         figsize = [11.326 7];
        figsize = [9.72 6];
        % figsize = [7 7];
        
        x_axpos = [2.8,-1.2];
        y_axpos = [-1,2];
        legend_fontsize = 15;
        axes_fontsize = 14;
        labels_fontsize = 18;
        n = [1 1];
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,1),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,torque_mod.Data(:,1),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)
         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-22 33], ...                               % Limits
                [-15:15:30], ...                            % Ticks
                {'-15','0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_1$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_1$','$\hat{\tau}_1$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque1_meas_mod_crit_damped

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,2),'Color',pacifica,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,torque_mod.Data(:,2),'Color',ddark_pacifica, 'LineStyle', '--','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1.3 91], ...                               % Limits
                [0:30:90], ...                            % Ticks
                {'0','30','60','90'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_2$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_2$','$\hat{\tau}_2$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque2_meas_mod_crit_damped

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,3),'Color',apple_yellow,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,torque_mod.Data(:,3),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-32 71], ...                               % Limits
                [-30:30:60], ...                            % Ticks
                {'-30','0','30','60'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_3$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_3$','$\hat{\tau}_3$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque3_meas_mod_crit_damped

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,4),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,torque_mod.Data(:,4),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.1 2.4], ...                               % Limits
                [0:1:2], ...                            % Ticks
                {'0','1','2'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_4$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_4$','$\hat{\tau}_4$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque4_meas_mod_crit_damped

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,5),'Color',pacifica,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,torque_mod.Data(:,5),'Color',ddark_pacifica, 'LineStyle', '--','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.1 0.9], ...                               % Limits
                [0:0.4:0.8], ...                            % Ticks
                {'0','0.4','0.8'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_5$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_5$','$\hat{\tau}_5$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque5_meas_mod_crit_damped

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,6),'Color',apple_yellow,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,torque_mod.Data(:,6),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1.4 1.5], ...                               % Limits
                [-1.3:1.3:1.3], ...                            % Ticks
                {'-1.3','0','1.3'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_6$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_6$','$\hat{\tau}_6$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque6_meas_mod_crit_damped

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------



axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,1)-torque_mod.Data(:,1),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,2)-torque_mod.Data(:,2),'Color',pacifica,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,3)-torque_mod.Data(:,3),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-31 70], ...                               % Limits
                [-30:30:60], ...                            % Ticks
                {'-30','0','30','60'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\tau,1}$, $\epsilon_{\tau,2}$, $\epsilon_{\tau,3}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\tau,1}$','$\epsilon_{\tau,2}$','$\epsilon_{\tau,3}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque123_mod_error_crit_damped


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,4)-torque_mod.Data(:,4),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,5)-torque_mod.Data(:,5),'Color',pacifica,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time,torque_target_measured.Data(:,6)-torque_mod.Data(:,6),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1.5 3], ...                               % Limits
                [-1.5:1.5:3], ...                            % Ticks
                {'-1.5','0','1.5','3'}, ...                      % Labels
                14 );                                    % Fontsize                          % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\tau,4}$, $\epsilon_{\tau,5}$, $\epsilon_{\tau,6}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\tau,4}$','$\epsilon_{\tau,5}$','$\epsilon_{\tau,6}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

%     % Create text
%     text('Parent',axes_h,'Interpreter','latex','String','$\epsilon$',...
%         'Position',[1.67114093959732 -0.00265079365079365 0],...
%         'FontSize',15);
% 
%     % Create arrow
%     annotation(figure_h,'arrow',[0.17 0.2],...
%         [0.2 0.29]);
% 
%     % Create arrow
%     annotation(figure_h,'arrow',[0.145 0.2],...
%         [0.2 0.26]);
% 
%     % Create arrow
%     annotation(figure_h,'arrow',[0.1 0.2],...
%         [0.2 0.268]);
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque456_mod_error_crit_damped
% -------------------------------------------------------------------------
% Close and clear all
% -------------------------------------------------------------------------   
    %close all
%     clear all
    disp('done!')

mean_torque_measured_1 = mean(torque_target_measured.Data(:,1))
mean_torque_measured_2 = mean(torque_target_measured.Data(:,2))
mean_torque_measured_3 = mean(torque_target_measured.Data(:,3))
mean_torque_measured_4 = mean(torque_target_measured.Data(:,4))
mean_torque_measured_5 = mean(torque_target_measured.Data(:,5))
mean_torque_measured_6 = mean(torque_target_measured.Data(:,6))
mean_torque_modelled_1 = mean(torque_mod.Data(:,1))
mean_torque_modelled_2 = mean(torque_mod.Data(:,2))
mean_torque_modelled_3 = mean(torque_mod.Data(:,3))
mean_torque_modelled_4 = mean(torque_mod.Data(:,4))
mean_torque_modelled_5 = mean(torque_mod.Data(:,5))
mean_torque_modelled_6 = mean(torque_mod.Data(:,6))