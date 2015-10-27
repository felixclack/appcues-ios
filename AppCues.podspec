Pod::Spec.new do |s|
  s.name = 'AppCues'
  s.version = '1.0.0'
  s.summary = 'The AppCues iOS SDK.'
  s.frameworks = %w(Foundation QuartzCore UIKit)
  s.requires_arc = true
  s.platform = :ios, '5.0'
  s.public_header_paths = 'Appcues/Appcues.h'
end
