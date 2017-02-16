
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
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,1),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,joint_variables_q_modelled.Data(:,1),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,2),'Color',pacifica,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_q_modelled.Data(:,2),'Color',ddark_pacifica, 'LineStyle', '--','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,3),'Color',apple_yellow,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_q_modelled.Data(:,3),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-3.2 1.5], ...                               % Limits
                [-3:1:1], ...                            % Ticks
                {'-3','-2','-1','0','1'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$q_1$, $q_2$, $q_3$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$q_1$','$\hat{q}_1$','$q_2$','$\hat{q}_2$','$q_3$','$\hat{q}_3$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 q123_meas_mod_crit_damped


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,4),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,joint_variables_q_modelled.Data(:,4),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,5),'Color',pacifica,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_q_modelled.Data(:,5),'Color',ddark_pacifica, 'LineStyle', '--','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,6),'Color',apple_yellow,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_q_modelled.Data(:,6),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-2.8 0], ...                               % Limits
                [-2:1:0], ...                            % Ticks
                {'-2','-1','0'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$q_4$, $q_5$, $q_6$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$q_4$','$\hat{q}_4$','$q_5$','$\hat{q}_5$','$q_6$','$\hat{q}_6$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 q456_meas_mod_crit_damped
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,1)-joint_variables_q_modelled.Data(:,1),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,2)-joint_variables_q_modelled.Data(:,2),'Color',pacifica,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,3)-joint_variables_q_modelled.Data(:,3),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.009 0.009], ...                               % Limits
                [-0.009:0.009:0.009], ...                            % Ticks
                {'-0.009','0','0.009'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_1$, $\epsilon_2$, $\epsilon_3$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_1$','$\epsilon_2$','$\epsilon_3$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 q123_mod_error_crit_damped


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,4)-joint_variables_q_modelled.Data(:,4),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,5)-joint_variables_q_modelled.Data(:,5),'Color',pacifica,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time,joint_variables_q_measured.Data(:,6)-joint_variables_q_modelled.Data(:,6),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.003 0.003], ...                               % Limits
                [-0.003:0.003:0.003], ...                            % Ticks
                {'-0.003','0','0.003'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\epsilon_4$, $\epsilon_5$, $\epsilon_6$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\epsilon_4$','$\epsilon_5$','$\epsilon_6$',...
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
print -depsc2 q456_mod_error_crit_damped
% -------------------------------------------------------------------------
% Close and clear all
% -------------------------------------------------------------------------   
    %close all
%     clear all
    disp('done!')