function [handle, axes_h] = jh_figures(Size,n,Axpos,FontSize)
% MR_FIGURE Generates a useful figure
%   [handle, axes_h] = mr_figures([width,height],[numCol,numRow],[xmargin,ymargin],FontSize) 
%   opens a new figure with the specified size in centimeters, 
%   TimesNewRoman as 'DefaultAxesFontName', 
%   and FontSize as DefaultAxesFontSize.
%   numCol and numRow give the number of subplots axes, with corresponding
%   handles, e.g. axes_h(1,2) for first column and second row.

%--------------------------------------------------------------------------
if nargout ~= 2
    error('jh_figures: exactly two outputs needed');
end

%--------------------------------------------------------------------------
% Default values
if nargin < 2
    % default: one subplot
    n = [1 1];
elseif numel(n) == 1
    n = [n n];
end

if nargin < 3
    % made with trial and error for nifty plots
    Axpos = [1.75 1.4]; %[2.40 1.8];
end

if nargin < 4
    FontSize = 7;
end

%--------------------------------------------------------------------------
% Einheiten einstellen -> macht manchmal hinterher Probleme!
set(0,   'DefaultFigureUnits',    'centimeters'  );
% Figure öffnen
handle = figure(  'Position',     [5 5 Size(1) Size(2)] );
set(gcf, 'PaperUnits',            'centimeters'  );
set(gcf, 'PaperPosition',         [0 0 Size(1) Size(2)] );
set(gcf, 'PaperSize',             [Size(1) Size(2)] );
%set(gcf, 'DefaultAxesFontName',   'TimesNewRoman');
%set(gcf, 'DefaultAxesFontSize',   FontSize       );
%set(gcf, 'DefaultTextFontName',   'TimesNewRoman');
%set(gcf, 'DefaultTextFontSize',   FontSize       );
set(gcf, 'DefaultLineLineWidth',  1.0            );
set(gcf, 'DefaultAxesLineWidth',  0.5            );
set(gcf, 'DefaultAxesBox',        'On');
set(gcf, 'DefaultAxesUnits',      'centimeters'  );
% set(gcf, 'DefaultAxesUnits',      'normalized');

%--------------------------------------------------------------------------
if( n(1)*n(2) ~= 0)
    % wenn Anzahl an Subplots gegeben

    % Groesse für Subplots ausrechnen
    subaxsize  = Size./n - Axpos - [0.094 0.114].*Axpos/n;

    % Subplot Axes erzeugen und handle an axes_h übergeben
    for col = 1:n(1)
        for row = 1:n(2)
            subaxpos = Axpos + ([1.0 1.0].*Axpos+subaxsize).*[col-1 row-1];
            eval(['axes_h(',num2str(col),',',num2str(row),') = mr_axis(subaxpos,subaxsize);']);
        end
    end
else
    axes_h = [];
end % if 

%end % function mr_figures
%--------------------------------------------------------------------------