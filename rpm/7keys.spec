Name: 7keys
Version: 1.0
Release: 1
Summary: A simple game, where your objective is escape a nazi facility   

License: MIT
URL: https://github.com/jpbusche/ManaTeam
Source0: ../SOURCES/%{name}-%{version}.tar.gz

BuildRequires: gcc, make, cmake, SDL2-devel, SDL2_image-devel, SDL2_ttf-devel, SDL2_mixer-devel

%description
You are Edmond Gauthier, a french sergeant, who are captured by the german army,
and put on a sanatorium. When your cell is accidentally open, you have just one desire: ESCAPE

%prep
%setup -q

%build
cmake .
make -j

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p ${RPM_BUILD_ROOT}/usr/bin
mkdir -p ${RPM_BUILD_ROOT}/etc/7keys/res
mv etc/7keys/res ${RPM_BUILD_ROOT}/etc/7keys/
cp -a 7keys ${RPM_BUILD_ROOT}/usr/bin/

%clean
rm -rf $RPM_BUILD_ROOT

%files
%license LICENSE
%defattr(-,root,root,-)
/usr/bin/7keys
/etc/7keys/

%changelog
* Mon Jun 19 2017 João Paulo Busche <joaopaulo.busche@gmail.com>
- 