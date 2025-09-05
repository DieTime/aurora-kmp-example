Name: com.example.aurorakmp
Summary: Example of usage KMP on Aurora OS
Version: 0.0.1
Release: 1
License: MIT
Source0: %{name}-%{version}.tar.zst

Requires: sailfishsilica-qt5
BuildRequires: pkgconfig(auroraapp)
BuildRequires: pkgconfig(Qt5Core)
BuildRequires: pkgconfig(Qt5Qml)
BuildRequires: pkgconfig(Qt5Quick)

%description
%{summary}.

%prep
%autosetup

%build
%qmake5
%make_build

%install
%make_install

%files
%{_bindir}/%{name}
%{_datadir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}.png
