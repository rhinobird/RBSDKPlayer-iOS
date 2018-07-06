Pod::Spec.new do |s|

  s.name         = "RBSDKPlayer"
  s.version      = "0.1.0"
  s.summary      = "Interactive video player SDK by Rhinobird"

  s.homepage     = "https://github.com/rhinobird/RBSDKPlayer"
  s.license      = "MIT"
  s.author       = { "Rhinobird Inc." => "benjamin@rhinobird.tv" }
  s.platform     = :ios, "10.3"

  s.source       = { :git => "git@github.com:rhinobird/RBSDKPlayer-iOS.git", :tag => "#{s.version}" }

  s.source_files = "RBSDKPlayer.framework/Headers/*.h"
  s.public_header_files = "RBSDKPlayer.framework/Headers/*.h"
  s.vendored_frameworks = "RBSDKPlayer.framework"

  s.dependency 'AWSS3', '~> 2.4.0'
  s.dependency 'MBCircularProgressBar', '~> 0.3'
  s.dependency 'Mixpanel', '~> 3.2'
  s.dependency 'NHNetworkTime', '~> 1.7'
  s.dependency 'SDWebImage', '~> 3.7'
  s.dependency 'XCDYouTubeKit', '~> 2.5'
  s.dependency 'Socket.IO-Client-Swift', '~> 12.0.0'

end
