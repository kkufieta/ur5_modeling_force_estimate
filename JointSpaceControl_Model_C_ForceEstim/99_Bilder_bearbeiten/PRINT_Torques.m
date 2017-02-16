
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
% mat_folder_name = 'RecordedUR5Data/Movement_No9_Singularity_Free_NoDist/mat_files/';
% mat_folder_name = 'RecordedUR5Data/Movement_No9_Singularity_Free_WDist/mat_files/';
% mat_folder_name = 'RecordedUR5Data/Movement_No9_Singularity_Free_ForceSensor/mat_files/';

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

start = 20;

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
    
    acc_green           = [116, 191, 69]/255;
    acc_red             = [196, 22, 27]/255;
    acc_orange          = [250, 164, 25]/255;
    acc_orange_dark     = [255, 129, 0]/255;
    acc_yellow          = [255, 222, 36]/255;
    acc_blue_dark       = [0, 81, 186]/255;
    acc_blue_darkish    = [0, 124, 196]/255;
    acc_blue_brighter   = [27, 142, 234]/255;

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
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,1),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time(start:end),torque_mod.Data(start:end,1),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)
         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-2 2.2], ...                               % Limits
                [-1.5:1.5:1.5], ...                            % Ticks
                {'-1.5','0','1.5'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_1$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_1$','$\hat{\tau}_1$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque1_meas_mod_Force_Estimation

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,2),'Color',blue,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time(start:end),torque_mod.Data(start:end,2),'Color',ddark_blue, 'LineStyle', '--','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [28 60], ...                               % Limits
                [30:15:60], ...                            % Ticks
                {'30','45','60'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_2$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_2$','$\hat{\tau}_2$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque2_meas_mod_Force_Estimation

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,3),'Color',apple_yellow,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time(start:end),torque_mod.Data(start:end,3),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [10 18], ...                               % Limits
                [10:4:18], ...                            % Ticks
                {'10','14','18'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_3$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_3$','$\hat{\tau}_3$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque3_meas_mod_Force_Estimation

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,4),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time(start:end),torque_mod.Data(start:end,4),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [1.15 1.7], ...                               % Limits
                [1.2:0.2:1.6], ...                            % Ticks
                {'1.2','1.4','1.6'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_4$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_4$','$\hat{\tau}_4$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque4_meas_mod_Force_Estimation

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,5),'Color',blue,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time(start:end),torque_mod.Data(start:end,5),'Color',ddark_blue, 'LineStyle', '--','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0.18 0.45], ...                               % Limits
                [0.2:0.1:0.4], ...                            % Ticks
                {'0.2','0.3','0.4'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_5$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_5$','$\hat{\tau}_5$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque5_meas_mod_Force_Estimation

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,6),'Color',apple_yellow,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time(start:end),torque_mod.Data(start:end,6),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.08 0.08], ...                               % Limits
                [-0.08:0.08:0.08], ...                            % Ticks
                {'-0.08','0','0.08'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\tau_6$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\tau_6$','$\hat{\tau}_6$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque6_meas_mod_Force_Estimation

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------



axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,1)-torque_mod.Data(start:end,1),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,2)-torque_mod.Data(start:end,2),'Color',blue,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,3)-torque_mod.Data(start:end,3),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-2.8 2.8], ...                               % Limits
                [-2.8:2.8:2.8], ...                            % Ticks
                {'-2.8','0','2.8'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\tau,1}$, $\epsilon_{\tau,2}$, $\epsilon_{\tau,3}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\tau,1}$','$\epsilon_{\tau,2}$','$\epsilon_{\tau,3}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque123_mod_error_Force_Estimation


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,4)-torque_mod.Data(start:end,4),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,5)-torque_mod.Data(start:end,5),'Color',blue,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time(start:end),torque_target_measured.Data(start:end,6)-torque_mod.Data(start:end,6),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.11 0.2], ...                               % Limits
                [-0.1:0.1:0.2], ...                            % Ticks
                {'-0.1','0','0.1','0.2'}, ...                      % Labels
                14 );                                    % Fontsize                          % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\tau,4}$, $\epsilon_{\tau,5}$, $\epsilon_{\tau,6}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\tau,4}$','$\epsilon_{\tau,5}$','$\epsilon_{\tau,6}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 torque456_mod_error_Force_Estimation
% -------------------------------------------------------------------------
% Close and clear all
% -------------------------------------------------------------------------   
    %close all
%     clear all
    disp('done!')
