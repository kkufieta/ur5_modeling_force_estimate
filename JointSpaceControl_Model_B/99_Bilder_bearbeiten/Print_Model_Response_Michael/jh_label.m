function jh_label(xlabl, ylabl, PosX, PosY,textsize)
%JH_LABEL Achslabel erzeugen
%   JH_LABEL(XLABEL,YLABEL) erzeugt zwei Label an der übergebenen Achse
%   an einer schriftgrößenabhängigen festen Position.
%
%   JH_LABEL(XLABEL,YLABEL,POSX,POSY) gibt die Position (in cm) fest vor.

    if nargin>=5
        if isempty(textsize)
            textsize = get(gca,'FontSize');
        end
    else
        textsize = get(gca,'FontSize');
    end
    
    if nargin>=3
        if isempty(PosX)
            h = get(gca, 'Position');
            PosX = [h(3)/2 -10/9];
        end
    end
    xlabel(xlabl, ...
           'Units','centimeters', ...
           'Position', PosX, ...
           'Interpreter', 'latex', ...
           'HorizontalAlignment', 'center', ...
           'VerticalAlignment', 'baseline', ...
           'Fontsize',textsize);

    if nargin>=4
        if isempty(PosY)
            h = get(gca, 'Position');
            PosY = [-7/7 h(4)/2];        
        end
    end
    ylabel(ylabl, ...
           'Units','centimeters', ...
           'Position', PosY, ...
           'Interpreter', 'latex', ...
           'HorizontalAlignment', 'center', ...
           'VerticalAlignment', 'baseline', ...
           'Fontsize',textsize);