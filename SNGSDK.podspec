
Pod::Spec.new do |s|

  s.name         = "SNGSDK"
  s.version      = "0.0.1"
  s.platform     = :ios, "5.0"
  s.source       = { :git => "https://github.com/yatouanqi/SNGSDK.git", :tag => "0.0.1" }
  s.source_files  = 'libSNGSDK/*.{h,m}'
  s.resource     = 'libSNGSDK/SNGResource.bundle'
  s.frameworks   = 'ImageIO', 'SystemConfiguration', 'CoreText', 'QuartzCore', 'Security', 'UIKit', 'Foundation', 'CoreGraphics','CoreTelephony'
  s.libraries = "iconv", "xml2",'sqlite3', 'z'
  # s.requires_arc = true
  s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  s.dependency 'SDWebImage', '~>3.7'


end
