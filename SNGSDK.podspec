
Pod::Spec.new do |s|

  s.name         = "SNGSDK"
  s.version      = "0.0.1"
  s.license      = "MIT (example)"
  s.platform     = :ios, "5.0"
  s.source       = { :git => "https://github.com/yatouanqi/SNGSDK.git", :tag => "0.0.1" }
  s.source_files  = "Classes", "Classes/**/*.{h,m}"
  s.resource     = 'libWeiboSDK/WeiboSDK.bundle'
  s.frameworks = "SomeFramework", "AnotherFramework"
  s.libraries = "iconv", "xml2"
  # s.requires_arc = true
  s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  s.dependency 'SDWebImage', '~>3.7'


end
