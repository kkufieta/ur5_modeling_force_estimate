
% -------------------------------------------------------------------------
% close all existing figures and clear workspace (might not be needed)
% -------------------------------------------------------------------------
%     clear all;
%  run('/Users/kasiunia/Documents/Diplomarbeit/DA_Matlab/JointSpaceControl_ForceEstim/99_Bilder_bearbeiten/Map_Currents_Torque.m')
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
    acc_red_light       = [239, 108, 112]/255;
    acc_orange          = [250, 164, 25]/255;
    acc_orange_dark     = [255, 129, 0]/255;
    acc_yellow          = [255, 222, 36]/255;
    acc_blue_dark       = [0, 81, 186]/255;
    acc_blue_darkish    = [0, 124, 196]/255;
    acc_blue_brighter   = [27, 142, 234]/255;
    acc_crazy_orange    = [255, 102, 0]/255;
    
    % Torque_Currents_Colors
    limoncello          = [247, 250, 65]/255;
    lemon_lime          = [154, 250, 65]/255;
    green_tea           = [42, 219, 133]/255;
    divider_blue        = [65, 154, 250]/255;
    cheer_violet        = [161, 65, 250]/255;
    limoncello_light    = [249, 251, 116]/255;
    
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
% Choose desired output format
% -------------------------------------------------------------------------
    % Fit axes and figure sizes to desired output format
        figsize = [18 6];
%         figsize = [9.72 6];
        % figsize = [7 7];
        
        x_axpos = [5.8,-1.2];
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

plot(force_sensor_measured.Time(sample_start:sample_end), force_sensor_measured.Data(sample_start:sample_end,1),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(force_sensor_measured.Time(sample_start:sample_end),good_force_estim_kathi(:,1),'Color',acc_blue_darkish,'LineWidth',1.2, 'LineStyle', '--'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-45 45], ...                               % Limits
                [-40:40:40], ...                            % Ticks
                {'-40','0','40'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$F_{x},~\hat{F}^*_x$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$F_{x}$', '$\hat{F}^*_x$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 good_force_estim_1


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,2),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t,good_force_estim_kathi(:,2),'Color',acc_blue_darkish,'LineWidth',1.2, 'LineStyle', '--'), hold on

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-25 35], ...                               % Limits
                [-20:20:20], ...                            % Ticks
                {'-20','0','20'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$$F_{y},~\hat{F}^*_y$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$F_{y}$', '$\hat{F}^*_y$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 good_force_estim_2
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,3),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t,good_force_estim_kathi(:,3),'Color',acc_blue_darkish,'LineWidth',1.2, 'LineStyle', '--'), hold on

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-50 30], ...                               % Limits
                [-40:20:20], ...                            % Ticks
                {'-40','-20','0','20'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$F_{z},~\hat{F}^*_z$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$F_{z}$', '$\hat{F}^*_z$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 good_force_estim_3


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,4),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t,good_force_estim_kathi(:,4),'Color',acc_blue_darkish,'LineWidth',1.2, 'LineStyle', '--'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-8 4], ...                               % Limits
                [-8:4:4], ...                            % Ticks
                {'-8','-4','0','4'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$n_{x},~\hat{n}^*_x$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$n_{x}$', '$\hat{n}^*_x$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 good_force_estim_4

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,5),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t,good_force_estim_kathi(:,5),'Color',acc_blue_darkish,'LineWidth',1.2, 'LineStyle', '-.'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-6 6], ...                               % Limits
                [-5:5:5], ...                            % Ticks
                {'-5','0','5'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$n_{y},~\hat{n}^*_y$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$n_{y}$', '$\hat{n}^*_y$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 good_force_estim_5

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,6),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t,good_force_estim_kathi(:,6),'Color',acc_blue_darkish,'LineWidth',1.2, 'LineStyle', '--'), hold on

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-3 3], ...                               % Limits
                [-2:2:2], ...                            % Ticks
                {'-2','0','2'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$n_{z},~\hat{n}^*_z$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$n_{z}$', '$\hat{n}^*_z$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 good_force_estim_6

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

%     limoncello          = [247, 250, 65]/255;
%     lemon_lime          = [154, 250, 65]/255;
%     green_tea           = [42, 219, 133]/255;

axes(axes_h(1,1))

plot(t, force_sensor_measured.Data(sample_start:sample_end,1),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t, force_ur5_modelled.Data(sample_start:sample_end,1),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t,bad_force_estim_kathi(:,1),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-130 130], ...                               % Limits
                [-130:130:130], ...                            % Ticks
                {'-130','0','130'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$F_{x},~\hat{F}^u_x,~\hat{F}_x$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$F_{x}$', '$\hat{F}^u_x$', '$\hat{F}_x$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 bad_force_estim_1


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,2),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t, force_ur5_modelled.Data(sample_start:sample_end,2),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t,bad_force_estim_kathi(:,2),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-100 100], ...                               % Limits
                [-100:100:100], ...                            % Ticks
                {'-100','0','100'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$F_{y},~\hat{F}^u_y,~\hat{F}_y$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$F_{y}$', '$\hat{F}^u_y$', '$\hat{F}_y$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 bad_force_estim_2
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,3),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t, force_ur5_modelled.Data(sample_start:sample_end,3),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t,bad_force_estim_kathi(:,3),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-50 20], ...                               % Limits
                [-40:20:20], ...                            % Ticks
                {'-40','-20','0','20'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$F_{z},~\hat{F}^u_z,~\hat{F}_z$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$F_{z}$', '$\hat{F}^u_z$', '$\hat{F}_z$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 bad_force_estim_3


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,4),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t, force_ur5_modelled.Data(sample_start:sample_end,4),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t,bad_force_estim_kathi(:,4),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-10 10], ...                               % Limits
                [-10:10:10], ...                            % Ticks
                {'-10','0','10'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$n_{x},~\hat{n}^u_x,~\hat{n}_x$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$n_{x}$', '$\hat{n}^u_x$', '$\hat{n}_x$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 bad_force_estim_4

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,5),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t, force_ur5_modelled.Data(sample_start:sample_end,5),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t,bad_force_estim_kathi(:,5),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-12 12], ...                               % Limits
                [-12:12:12], ...                            % Ticks
                {'-12','0','12'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$n_{y},~\hat{n}^u_y,~\hat{n}_y$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$n_{y}$', '$\hat{n}^u_y$', '$\hat{n}_y$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 bad_force_estim_5

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,6),'Color',acc_red_light,'LineWidth',1.2), hold on
plot(t, force_ur5_modelled.Data(sample_start:sample_end,6),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t,bad_force_estim_kathi(:,6),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-5 7], ...                               % Limits
                [-5:5:5], ...                            % Ticks
                {'-5','0','5'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$n_{z},~\hat{n}^u_z,~\hat{n}_z$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$n_{z}$', '$\hat{n}^u_z$', '$\hat{n}_z$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 bad_force_estim_6

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

%     limoncello          = [247, 250, 65]/255;
%     lemon_lime          = [154, 250, 65]/255;
%     green_tea           = [42, 219, 133]/255;

axes(axes_h(1,1))

plot(t, force_sensor_measured.Data(sample_start:sample_end,1) - force_ur5_modelled.Data(sample_start:sample_end,1),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,1) - bad_force_estim_kathi(:,1),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,1) - good_force_estim_kathi(:,1),'Color',acc_blue_darkish,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-150 90], ...                               % Limits
                [-140:70:70], ...                            % Ticks
                {'-140','-70','0','70'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon^u_{F_x}$, $\epsilon_{F_x}$, $\epsilon^*_{F_x}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon^u_{F_x}$', '$\epsilon_{F_x}$', '$\epsilon^*_{F_x}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 force_estim_errors_1


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,2) - force_ur5_modelled.Data(sample_start:sample_end,2),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,2) - bad_force_estim_kathi(:,2),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,2) - good_force_estim_kathi(:,2),'Color',acc_blue_darkish,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-105 105], ...                               % Limits
                [-100:100:100], ...                            % Ticks
                {'-100','0','100'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon^u_{F_y}$, $\epsilon_{F_y}$, $\epsilon^*_{F_y}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon^u_{F_y}$', '$\epsilon_{F_y}$', '$\epsilon^*_{F_y}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 force_estim_errors_2
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,3) - force_ur5_modelled.Data(sample_start:sample_end,3),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,3) - bad_force_estim_kathi(:,3),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,3) - good_force_estim_kathi(:,3),'Color',acc_blue_darkish,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-37 37], ...                               % Limits
                [-35:35:35], ...                            % Ticks
                {'-35','0','35'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon^u_{F_z}$, $\epsilon_{F_z}$, $\epsilon^*_{F_z}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon^u_{F_z}$', '$\epsilon_{F_z}$', '$\epsilon^*_{F_z}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 force_estim_errors_3


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,4) - force_ur5_modelled.Data(sample_start:sample_end,4),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,4) - bad_force_estim_kathi(:,4),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,4) - good_force_estim_kathi(:,4),'Color',acc_blue_darkish,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-9 9], ...                               % Limits
                [-8:8:8], ...                            % Ticks
                {'-8','0','8'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon^u_{n_x}$, $\epsilon_{n_x}$, $\epsilon^*_{n_x}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon^u_{n_x}$', '$\epsilon_{n_x}$', '$\epsilon^*_{n_x}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 force_estim_errors_4

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,5) - force_ur5_modelled.Data(sample_start:sample_end,5),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,5) - bad_force_estim_kathi(:,5),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,5) - good_force_estim_kathi(:,5),'Color',acc_blue_darkish,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-12.5 12.5], ...                               % Limits
                [-11:11:11], ...                            % Ticks
                {'-11','0','11'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon^u_{n_y}$, $\epsilon_{n_y}$, $\epsilon^*_{n_y}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon^u_{n_y}$', '$\epsilon_{n_y}$', '$\epsilon^*_{n_y}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 force_estim_errors_5

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(t, force_sensor_measured.Data(sample_start:sample_end,6) - force_ur5_modelled.Data(sample_start:sample_end,6),'Color',green_tea,'LineWidth',1.2, 'LineStyle', '--'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,6) - bad_force_estim_kathi(:,6),'Color',cheer_violet,'LineWidth',1.2, 'LineStyle', '-.'), hold on
plot(t, force_sensor_measured.Data(sample_start:sample_end,6) - good_force_estim_kathi(:,6),'Color',acc_blue_darkish,'LineWidth',1.2), hold on



         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 34], ...                               % Limits
                [0:15:30], ...                          % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-8 5], ...                               % Limits
                [-8:4:4], ...                            % Ticks
                {'-8','-4','0','4'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon^u_{n_z}$, $\epsilon_{n_z}$, $\epsilon^*_{n_z}$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon^u_{n_z}$', '$\epsilon_{n_z}$', '$\epsilon^*_{n_z}$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 force_estim_errors_6



% -------------------------------------------------------------------------
% Close and clear all
% -------------------------------------------------------------------------   
    %close all
%     clear all
    disp('done!')
