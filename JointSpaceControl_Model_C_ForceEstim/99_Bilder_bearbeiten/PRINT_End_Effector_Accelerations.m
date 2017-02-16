
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
    acc_crazy_orange    = [255, 102, 0]/255;

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
         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_base.Data(start:end,1),'Color',acc_crazy_orange,'LineWidth',1.2), hold on
         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_mod.Data(start:end,1),'Color',acc_blue_brighter, 'LineStyle', '-.','LineWidth',1.1)
         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-2 2], ...                               % Limits
                [-2:2:2], ...                            % Ticks
                {'-2','0','2'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\ddot{X}_1$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\ddot{X}_1$','$\hat{\ddot{X}}_1$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_X

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_base.Data(start:end,2),'Color',acc_crazy_orange,'LineWidth',1.2), hold on
         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_mod.Data(start:end,2),'Color',acc_blue_brighter, 'LineStyle', '--','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\ddot{X}_2$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\ddot{X}_2$','$\hat{\ddot{X}}_2$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Y

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_base.Data(start:end,3),'Color',acc_crazy_orange,'LineWidth',1.2), hold on
         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_mod.Data(start:end,3),'Color',acc_blue_brighter, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\ddot{X}_3$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\ddot{X}_3$','$\hat{\ddot{X}}_3$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Z

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_base.Data(start:end,1),'Color',acc_crazy_orange,'LineWidth',1.2), hold on
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_mod.Data(start:end,1),'Color',acc_blue_brighter, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-40 60], ...                               % Limits
                [-30:30:60], ...                            % Ticks
                {'-30','0','30','60'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\ddot{X}_4$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\ddot{X}_4$','$\hat{\ddot{X}}_4$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Rx

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_base.Data(start:end,2),'Color',acc_crazy_orange,'LineWidth',1.2), hold on
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_mod.Data(start:end,2),'Color',acc_blue_brighter, 'LineStyle', '--','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-8 8], ...                               % Limits
                [-8:8:8], ...                            % Ticks
                {'-8','0','8'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\ddot{X}_5$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\ddot{X}_5$','$\hat{\ddot{X}}_5$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Ry

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_base.Data(start:end,3),'Color',acc_crazy_orange,'LineWidth',1.2), hold on
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_mod.Data(start:end,3),'Color',acc_blue_brighter, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-35 60], ...                               % Limits
                [-30:30:60], ...                            % Ticks
                {'-30','0','30','60'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\ddot{X}_6$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\ddot{X}_6$','$\hat{\ddot{X}}_6$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Rz

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------



axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_base.Data(start:end,1)-acc_XYZ_mod.Data(start:end,1),'Color',acc_blue_darkish,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-2 2], ...                               % Limits
                [-2:2:2], ...                            % Ticks
                {'-2','0','2'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\ddot{X},1}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\ddot{X},1}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_X_mod_error
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------



axes(axes_h(1,1))

         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_base.Data(start:end,2)-acc_XYZ_mod.Data(start:end,2),'Color',acc_blue_darkish,'LineWidth',1.2)


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\ddot{X},2}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\ddot{X},2}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Y_mod_error

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------



axes(axes_h(1,1))

         plot(acc_XYZ_mod.Time(start:end),acc_XYZ_base.Data(start:end,3)-acc_XYZ_mod.Data(start:end,3),'Color',acc_blue_darkish,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\ddot{X},3}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\ddot{X},3}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Z_mod_error

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_base.Data(start:end,1)-acc_RxRyRz_mod.Data(start:end,1),'Color',acc_blue_darkish,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-60 40], ...                               % Limits
                [-60:30:30], ...                            % Ticks
                {'-60','-30','0','30'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\ddot{X},4}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\ddot{X},4}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Rx_mod_error

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))

         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_base.Data(start:end,2)-acc_RxRyRz_mod.Data(start:end,2),'Color',acc_blue_darkish,'LineWidth',1.2)


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-8 8], ...                               % Limits
                [-8:8:8], ...                            % Ticks
                {'-8','0','8'}, ...                      % Labels
                14 );                                    % Fontsize                        % Fontsize
        jh_label('$t~[s]$','$$\epsilon_{\ddot{X},5}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\ddot{X},5}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Ry_mod_error

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------


axes(axes_h(1,1))
         plot(acc_XYZ_mod.Time(start:end),acc_RxRyRz_base.Data(start:end,3)-acc_RxRyRz_mod.Data(start:end,3),'Color',acc_blue_darkish,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-60 40], ...                               % Limits
                [-60:30:30], ...                            % Ticks
                {'-60','-30','0','30'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_{\ddot{X},6}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_{\ddot{X},6}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 acc_Rz_mod_error
% -------------------------------------------------------------------------
% Close and clear all
% -------------------------------------------------------------------------   
    %close all
%     clear all
    disp('done!')
