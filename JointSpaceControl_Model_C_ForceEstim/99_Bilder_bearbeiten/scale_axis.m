function scale_axis(achse, scl, lim, tck, labl, fs);
%SCALE_AXIS Achse skalieren
%   SCALE_AXIS(ACHSE,LINLOG,LIM) skaliert die übergebene Achse
%   ('x'/'y'/'z') linear bzw. logarithmisch ('lin'/'log') und setzt die
%   in LIM übergebenen Grenzen.
%
%   SCALE_AXIS(ACHSE,LINLOG,LIM,TICK) setzt zusätzlich feste Ticks
%
%   SCALE_AXIS(ACHSE,LINLOG,LIM,TICK,LABEL) gibt die Bezeichnungen der
%   Label mit an.
%   Tip:
%   LABEL={} erzeugt Achsen ohne Beschriftung,
%   LABEL={'0,0' '0,5'} erzeugt Beschriftungen mit Dezimalkommas.

if iscellstr(scl) == 1
    set(gca, [achse 'Scale'], char(scl(1,1)) );
    set(gca, [achse 'Grid'],  char(scl(1,2)) );       
else
    set(gca, [achse 'Scale'], scl );
    set(gca, [achse 'Grid'], 'on');
end

if nargin > 2
    set(gca, [achse 'Lim'], lim);
end
if nargin > 3
    set(gca, [achse 'Tick'], tck);
end
if nargin > 4
    set(gca, [achse 'TickLabel'], labl);
end
if nargin > 5
    set(gca, 'Fontsize', fs);
end