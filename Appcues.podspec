Pod::Spec.new do |s|
  s.authors = { 'Jonathan Kim' => '@hijonathan' }
  s.compiler_flags = '-ObjC -all_load'
  s.frameworks = %w(Foundation QuartzCore UIKit)
  s.homepage = 'https://github.com/appcues/appcues-ios'
  s.ios.vendored_library = 'Appcues/libAppcues.a'
  s.license = { type: 'Apache license', file: 'LICENSE' }
  s.name = 'Appcues'
  s.platform = :ios, '5.0'
  s.public_header_files = 'Appcues/Appcues.h'
  s.requires_arc = true
  s.source = { git: 'https://github.com/felixclack/appcues-ios.git', tag: s.version.to_s }
  s.source_files = 'Appcues/Appcues.h'
  s.summary = 'The AppCues iOS SDK.'
  s.version = '1.0.1'
end
