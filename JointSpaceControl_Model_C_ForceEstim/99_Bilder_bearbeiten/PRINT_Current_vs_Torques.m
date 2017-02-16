
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
%         figsize = [11.326 7];
        figsize = [7.5 6];
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

plot(i_actual_measured.Data(sample_start:sample_end,1), torque_mod.Data(sample_start:sample_end,1),'Color',acc_blue_brighter,'LineWidth',1.2), hold on

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-5 5], ...                               % Limits
                [-5:5:5], ...                          % Ticks
                {'-5','0','5'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-5 15], ...                               % Limits
                [-5:10:15], ...                            % Ticks
                {'-5','5','15'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_1$','$\hat{\tau}_{\mu,1}$',x_axpos,y_axpos,labels_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,1}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_1


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,2), torque_mod.Data(sample_start:sample_end,2),'Color',acc_blue_brighter,'LineWidth',1.2), hold on

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 10], ...                               % Limits
                [0:5:10], ...                            % Ticks
                {'0','5','10'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [30 60], ...                               % Limits
                [30:15:60], ...                            % Ticks
                {'30','45','60'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_2$','$\hat{\tau}_{\mu,2}$',x_axpos,y_axpos,labels_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,2}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_2
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,3), torque_mod.Data(sample_start:sample_end,3),'Color',acc_blue_brighter,'LineWidth',1.2), hold on

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-5 5], ...                               % Limits
                [-5:5:5], ...                            % Ticks
                {'-5','0','5'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [12 18], ...                               % Limits
                [12:3:18], ...                            % Ticks
                {'12','15','18'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_3$','$\hat{\tau}_{\mu,3}$',x_axpos,y_axpos,labels_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,3}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_3


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,4), torque_mod.Data(sample_start:sample_end,4),'Color',acc_blue_brighter,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0.6 1.6], ...                               % Limits
                [0.6:0.5:1.6], ...                            % Ticks
                {'0.6','1.1','1.6'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_4$','$\hat{\tau}_{\mu,4}$',x_axpos,y_axpos,labels_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,4}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_4

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,5), torque_mod.Data(sample_start:sample_end,5),'Color',acc_blue_brighter,'LineWidth',1.2), hold on


         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.2 0.3], ...                               % Limits
                [-0.2:0.5:0.3], ...                            % Ticks
                {'-0.2','0.3'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_5$','$\hat{\tau}_{\mu,5}$',x_axpos,y_axpos,labels_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,5}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_5

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,6), torque_mod.Data(sample_start:sample_end,6),'Color',acc_blue_brighter,'LineWidth',1.2), hold on

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1.5 1.5]*10^(-3), ...                               % Limits
                [-1.5:1.5:1.5]*10^(-3), ...                            % Ticks
                {'-1.5','0','1.5'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_6$','$\hat{\tau}_{\mu,6}~ \cdot 10^{3}$',x_axpos,y_axpos,labels_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,6}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_6

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))

plot(i_actual_measured.Data(sample_start:sample_end,1), torque_w_friction.Data(sample_start:sample_end,1),'Color',acc_blue_brighter,'LineWidth',1.2), hold on
plot([-3,3], 7.5*[-3, 3]-0.61,'Color','k','LineWidth',1.9, 'LineStyle', '--')

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-5 5], ...                               % Limits
                [-5:5:5], ...                          % Ticks
                {'-5','0','5'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-15 15], ...                               % Limits
                [-15:15:15], ...                            % Ticks
                {'-15','0','15'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_1$','$\hat{\tau}_{\mu,1} + \hat{\tau}_{fr,1}$',x_axpos,y_axpos,labels_fontsize);
        t1 = text(-0.3, -13, '$7.5\,i_1-0.6$', 'Color', 'k');
        set(t1,'Interpreter','Latex','FontSize',legend_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,1} + \hat{\tau}_{\mu,1}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_w_fr_1


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,2), torque_w_friction.Data(sample_start:sample_end,2),'Color',acc_blue_brighter,'LineWidth',1.2), hold on
plot([0,10], 6.8*[0, 10]+16,'Color','k','LineWidth',1.9, 'LineStyle', '--')

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 10], ...                               % Limits
                [0:5:10], ...                            % Ticks
                {'0','5','10'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [20 70], ...                               % Limits
                [20:25:70], ...                            % Ticks
                {'20','45','70'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_2$','$\hat{\tau}_{\mu,2} + \hat{\tau}_{fr,2}$',x_axpos,y_axpos,labels_fontsize);
        t1 = text(5, 24, '$6.8\,i_2+16$', 'Color', 'k');
        set(t1,'Interpreter','Latex','FontSize',legend_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,2} + \hat{\tau}_{\mu,2}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_w_fr_2
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,3), torque_w_friction.Data(sample_start:sample_end,3),'Color',acc_blue_brighter,'LineWidth',1.2), hold on
plot([-5,5], 7.1*[-5, 5]+4.5,'Color','k','LineWidth',1.9, 'LineStyle', '--')

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-5 5], ...                               % Limits
                [-5:5:5], ...                            % Ticks
                {'-5','0','5'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 30], ...                               % Limits
                [0:15:30], ...                            % Ticks
                {'0','15','30'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_3$','$\hat{\tau}_{\mu,3} + \hat{\tau}_{fr,3}$',x_axpos,y_axpos,labels_fontsize);
        t1 = text(-4, 23, '$7.1\,i_3+4.5$', 'Color', 'k');
        set(t1,'Interpreter','Latex','FontSize',legend_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,3} + \hat{\tau}_{\mu,3}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_w_fr_3


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,4), torque_w_friction.Data(sample_start:sample_end,4),'Color',acc_blue_brighter,'LineWidth',1.2), hold on
plot([-1,1], 2.8*[-1, 1]+0.84,'Color','k','LineWidth',1.9, 'LineStyle', '--')

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 3], ...                               % Limits
                [-1:2:3], ...                            % Ticks
                {'-1','1','3'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_4$','$\hat{\tau}_{\mu,4} + \hat{\tau}_{fr,4}$',x_axpos,y_axpos,labels_fontsize);
        t1 = text(-0.2, -0.7, '$2.8\,i_4+0.84$', 'Color', 'k');
        set(t1,'Interpreter','Latex','FontSize',legend_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,4} + \hat{\tau}_{\mu,4}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_w_fr_4

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,5), torque_w_friction.Data(sample_start:sample_end,5),'Color',acc_blue_brighter,'LineWidth',1.2), hold on
plot([-1,1], 3.2*[-1, 1]+0.064,'Color','k','LineWidth',1.9, 'LineStyle', '--')

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1.5 1.5], ...                               % Limits
                [-1.5:1.5:1.5], ...                            % Ticks
                {'-1.5','0','1.5'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_5$','$\hat{\tau}_{\mu,5} + \hat{\tau}_{fr,5}$',x_axpos,y_axpos,labels_fontsize);
        t1 = text(-0.2, -1.3, '$3.2\,i_5+0.06$', 'Color', 'k');
        set(t1,'Interpreter','Latex','FontSize',legend_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,5} + \hat{\tau}_{\mu,5}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);


% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_w_fr_5

% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
plot(i_actual_measured.Data(sample_start:sample_end,6), torque_w_friction.Data(sample_start:sample_end,6),'Color',acc_blue_brighter,'LineWidth',1.2), hold on
plot([-1,1], 3.4*[-1, 1]+0.099,'Color','k','LineWidth',1.9, 'LineStyle', '--')

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1 1], ...                               % Limits
                [-1:1:1], ...                            % Ticks
                {'-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1.5 1.5], ...                               % Limits
                [-1.5:1.5:1.5], ...                            % Ticks
                {'-1.5','0','1.5'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$i_6$','$\hat{\tau}_{\mu,6} + \hat{\tau}_{fr,6}$',x_axpos,y_axpos,labels_fontsize);
        t1 = text(-0.1, -1.3, '$3.4\,i_6+0.1$', 'Color', 'k');
        set(t1,'Interpreter','Latex','FontSize',legend_fontsize);
%         l1 = legend('$\hat{\tau}_{\mu,6} + \hat{\tau}_{\mu,6}$',...
%             'Location','EastOutside')
%          set(l1,'Interpreter','Latex','FontSize',legend_fontsize);

% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 current_torque_w_fr_6
% -------------------------------------------------------------------------
% Close and clear all
% -------------------------------------------------------------------------   
    %close all
%     clear all
    disp('done!')
