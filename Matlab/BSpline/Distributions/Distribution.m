classdef (Abstract) Distribution
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        pdf     % probability density function
        cdf     % cumulative distribution function
        rho     % autocorrelation function
        
        variance    % total variance

        w           % 'weight' function, 
        dPDFoverZ   % derivative of the pdf wrt z, divided by z
        logPDF      % log of the pdf
    end
    
    methods
        function z = locationOfCDFPercentile(self, alpha)
            assert( alpha > 0 & alpha < 1,'alpha must be between 0 and 1');       
            z = fminsearch(@(z) abs(self.cdf(z)-alpha),0);
        end
        
        function var = varianceInRange(self,zmin,zmax)
           var = integral( @(z) z.*z.*self.pdf(z),zmin,zmax);
        end
        
        function var = varianceInPercentileRange(self,pctmin,pctmax)
            zmin = self.locationOfCDFPercentile(pctmin);
            zmax = self.locationOfCDFPercentile(pctmax);
            var = self.varianceInRange(zmin,zmax);
        end
        
        function totalError = andersonDarlingError(self,epsilon)
            Y = sort(epsilon);
            n = length(Y);
            
            s = ((2*(1:n)'-1)/n) .* (log(self.cdf(Y)) + log(1-self.cdf(flip(Y))));
            
            totalError = -n-sum(s);
        end
        
        function totalError = andersonDarlingInterquartileError(self,epsilon)
            Y = sort(epsilon);
            n = length(Y);
            
            s = ((2*(1:n)'-1)/n) .* (log(self.cdf(Y)) + log(1-self.cdf(flip(Y))));
            sIQ = s(floor(n/4):ceil(3*n/4));
            
            totalError = length(sIQ)-sum(sIQ);
        end
        
        function totalError = kolmogorovSmirnovError(self,epsilon,zmin,zmax)
            if nargin == 4
                x = sort(epsilon( epsilon > zmin & epsilon < zmax ));
                A = 1/(self.cdf(zmax)-self.cdf(zmin));
                b = self.cdf(zmin);
            else
                x = sort(epsilon);
                A = 1;
                b = 0;
            end
            
            n = length(x);
            y_data = (1:n)'/n;
            y = A*(self.cdf(x)-b);
            
            D = max(abs(y-y_data));
            
            totalError = (sqrt(n) + 0.12 + 0.11/sqrt(n))*D;
            if isempty(totalError)
                totalError = Inf;
            end
        end
        
        function totalError = kolmogorovSmirnovInterquartileError(self,epsilon)
            x = sort(epsilon);
            n = length(x);
            y_data = (1:n)'/n;
            y = self.cdf(x);
            
            ks = y-y_data;
            DIQ = max(abs(ks(floor(n/4):ceil(3*n/4))));
            n = length(DIQ);
            
            totalError = (sqrt(n) + 0.12 + 0.11/sqrt(n))*DIQ;
        end
        
        function y = rand(self,n)
            pct = 1/1e5;
            zmin = self.locationOfCDFPercentile(pct/2);
            zmax = self.locationOfCDFPercentile(1-pct/2);
            binEdges = linspace(zmin,zmax,1e5+1)';
            binWidths = diff(binEdges);
            binEdges_cdf = self.cdf(binEdges); % maps the bin edges [0, 1]
            [~, ~, bin] = histcounts(rand(n+10,1),binEdges_cdf);
            bin(bin==0 | bin == length(binWidths+1)) = [];
            y = binEdges(bin) + rand(length(bin),1).*binWidths(bin);
            y = y(1:n);
        end
    end
end
