dane1 = csvread('litery.csv', 0, 0);
dane2= csvread('litery2.csv', 0, 0);
dane3= csvread('litery3.csv', 0, 0);
input=csvread('input.csv', 0, 0);
A=csvread('A.csv', 0, 0);
B=csvread('B.csv', 0, 0);
C=csvread('C.csv', 0, 0);
D=csvread('D.csv', 0, 0);
E=csvread('E.csv', 0, 0);
F=csvread('F.csv', 0, 0);
G=csvread('G.csv', 0, 0);
H=csvread('H.csv', 0, 0);
I=csvread('I.csv', 0, 0);
J=csvread('J.csv', 0, 0);
K=csvread('K.csv', 0, 0);
L=csvread('L.csv', 0, 0);
M=csvread('M.csv', 0, 0);
N=csvread('N.csv', 0, 0);
O=csvread('O.csv', 0, 0);
P=csvread('P.csv', 0, 0);
Q=csvread('Q.csv', 0, 0);
R=csvread('R.csv', 0, 0);
S=csvread('S.csv', 0, 0);
T=csvread('T.csv', 0, 0);



    character=csvread('K.csv', 0, 0); 
    digits = reshape(character(1, 1:end), [7,8])'
    for i = 2:4
        digit = reshape(character(i, 1:end), [7,8])'
        digits=[digits digit]                   
    end



colormap(gray);
s = char(76:84); % Or just use: s = 'abcdefghijklmnopqrstuvwxyz';
for ns = 1:length(s)
    filename = [s(ns),'.csv']
    character=csvread(filename, 0, 0);
    
    row = reshape(character(1, 1:end), [7,8])'
    for i = 2:4
        digit = reshape(character(i, 1:end), [7,8])'
        row=[row digit]                   
    end
    digits=[digits; [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]];
    digits=[digits; row];
end


imagesc(digits)  


%wagi = ((rand(56,20)*6) - 3); %3 neurony, 56 wejœæ dla ka¿dego
%wyniki=sin(dane1*wagi)




%[m,maxIndex]=max(wyniki);

%wagi(:,maxIndex(1))';
%dane1(1,:)';
%wyniki(maxIndex(1),1);

%lp.lr = 0.001;

%for j= 1:1000
    %for i = 1:20

        
        %wagi(:,maxIndex(i))=wagi(:,maxIndex(i))+ learnk(wagi(:,maxIndex(i))',dane1(i,:)',[],[],wyniki(maxIndex(i),i),[],[],[],[],[],lp,[])';
        %wagi(:,maxIndex(i))=wagi(:,maxIndex(i))+ learnk(wagi(:,maxIndex(i))',dane(i,:)',[],[],wyniki(maxIndex(i),i),[],[],[],[],[],lp,[])';

    %end
%end

%wyniki=sin(dane1*wagi)

%[m,maxIndex]=max(wyniki)

%dane1 = csvread('litery2.csv', 0, 0);
%wyniki=sin(dane1*wagi)
%[m,maxIndex]=max(wyniki)
