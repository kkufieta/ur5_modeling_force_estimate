
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
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,1),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,joint_variables_dq_modelled.Data(:,1),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,2),'Color',pacifica,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_dq_modelled.Data(:,2),'Color',ddark_pacifica, 'LineStyle', '--','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,3),'Color',apple_yellow,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_dq_modelled.Data(:,3),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-3.5 3.5], ...                               % Limits
                [-3.5:3.5:3.5], ...                            % Ticks
                {'-3.5','0','3.5'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\dot{q}_1$, $\dot{q}_2$, $\dot{q}_3$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\dot{q}_1$','$\hat{\dot{q}}_1$','$\dot{q}_2$','$\hat{\dot{q}}_2$','$\dot{q}_3$','$\hat{\dot{q}}_3$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 dq123_meas_mod_crit_damped


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,4),'Color',light_cherry_pink,'LineWidth',1.2), hold on
         plot(joint_variables_q_modelled.Time,joint_variables_dq_modelled.Data(:,4),'Color',ddark_cherry_pink, 'LineStyle', '-.','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,5),'Color',pacifica,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_dq_modelled.Data(:,5),'Color',ddark_pacifica, 'LineStyle', '--','LineWidth',1.1)
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,6),'Color',apple_yellow,'LineWidth',1.2)
         plot(joint_variables_q_modelled.Time,joint_variables_dq_modelled.Data(:,6),'Color',ddark_apple_yellow, 'LineStyle', '-.','LineWidth',1.1)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-1.1 1.1], ...                               % Limits
                [-1.1:1.1:1.1], ...                            % Ticks
                {'-1.1','0','1.1'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\dot{q}_4$, $\dot{q}_5$, $\dot{q}_6$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\dot{q}_4$','$\hat{\dot{q}}_4$','$\dot{q}_5$','$\hat{\dot{q}}_5$','$\dot{q}_6$','$\hat{\dot{q}}_6$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 dq456_meas_mod_crit_damped
% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,1)-joint_variables_dq_modelled.Data(:,1),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,2)-joint_variables_dq_modelled.Data(:,2),'Color',pacifica,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,3)-joint_variables_dq_modelled.Data(:,3),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.27 0.27], ...                               % Limits
                [-0.27:0.27:0.27], ...                            % Ticks
                {'-0.27','0','0.27'}, ...                      % Labels
                14 );                                    % Fontsize
        jh_label('$t~[s]$','$\dot{\epsilon}_1$, $\dot{\epsilon}_2$, $\dot{\epsilon}_3$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\dot{\epsilon}_1$','$\dot{\epsilon}_2$','$\dot{\epsilon}_3$',...
            'Location','EastOutside')
         set(l1,'Interpreter','Latex','FontSize',legend_fontsize);
        
% -------------------------------------------------------------------------
% Print plot
% -------------------------------------------------------------------------   
print -depsc2 dq123_mod_error_crit_damped


% -------------------------------------------------------------------------
% open new figure with appropriate size
% -------------------------------------------------------------------------
         [figure_h, axes_h] = jh_figures(figsize,[1 1]);%,2,axpos,18);

% -------------------------------------------------------------------------
% Generate plots, scale axis and add labels
% -------------------------------------------------------------------------

axes(axes_h(1,1))
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,4)-joint_variables_dq_modelled.Data(:,4),'Color',cherry_pink,'LineWidth',1.2,'LineStyle', '-.'), hold on
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,5)-joint_variables_dq_modelled.Data(:,5),'Color',pacifica,'LineWidth',1.2,'LineStyle', '--')
         plot(joint_variables_q_measured.Time,joint_variables_dq_measured.Data(:,6)-joint_variables_dq_modelled.Data(:,6),'Color',dark_apple_yellow,'LineWidth',1.2)

         scale_axis( 'x', ...                            % scale x-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [0 20], ...                               % Limits
                [0:10:20], ...                          % Ticks
                {'0','10','20'}, ...                      % Labels
                14 );                                    % Fontsize
        scale_axis( 'y', ...                             % scale y-axis
                {'lin','off'}, ...                       % scaling 'lin' or 'log', Grid 'on' or 'off
                [-0.1 0.1], ...                               % Limits
                [-0.1:0.1:0.1], ...                            % Ticks
                {'-0.1','0','0.1'}, ...                      % Labels
                14 );                                    % Fontsize                            % Fontsize
        jh_label('$t~[s]$','$\dot{\epsilon}_4$, $\dot{\epsilon}_5$, $\dot{\epsilon}_6$',x_axpos,y_axpos,labels_fontsize);
        l1 = legend('$\dot{\epsilon}_4$','$\dot{\epsilon}_5$','$\dot{\epsilon}_6$',...
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
print -depsc2 dq456_mod_error_crit_damped
% -------------------------------------------------------------------------
% Close and clear all
% -------------------------------------------------------------------------   
    %close all
%     clear all
    disp('done!')